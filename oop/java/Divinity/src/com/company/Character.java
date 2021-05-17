package com.company;

import java.util.ArrayList;
import java.util.List;

//- добавете полета за инвентара и хотбара в клас Character
//        - в инвентара могат да се слагат всякакви предмети, а в хотбара само такива, които имплементират интерфейса Equippable
//        - добавете метод void pick(Item newItem); ако има място в инвентара предметите се слагат в първия свободен слот,
//        ако предметът е Equippable и има свободен слот в хотбара - се добавя и там (отново в първия свободен слот).
//        При опит да се вземе предмет и пълен инвентар - да се хвърля Exception
//        - добавете метод void useAt(int index, Character target), който използва предмет от хотбара:
//        - Ако предметът е Consumable - той се консумира (Пример: Potion ще промени кръвта/маната на този,
//        който използва предмета си от инвентара) и ако е подаден target - той се игнорира
//        - Ако предметът е Usable, това означава, че той се използва върху друг герой

public abstract class Character {
    private double CurrentHealth;
    private int MaxHealth;
    private int Intelligence;
    private int Dextirity;
    private List<Item> inventory = new ArrayList<>();
    private List<Item> hotBar = new ArrayList<>();

    public Character(int maxHealth, int intelligence, int dextirity) {
        MaxHealth = maxHealth;
        CurrentHealth = maxHealth;
        Intelligence = intelligence;
        Dextirity = dextirity;
    }

    public Character() {
    }

    public int getMaxHealth() {
        return MaxHealth;
    }

    public int getIntelligence() {
        return Intelligence;
    }

    public double getCurrentHealth() {
        return CurrentHealth;
    }

    public void setMaxHealth(int maxHealth) {
        MaxHealth = maxHealth;
    }

    public void setIntelligence(int intelligence) {
        Intelligence = intelligence;
    }

    public void setDextirity(int dextirity) {
        Dextirity = dextirity;
    }

    public void setCurrentHealth(double MaxHealth) {
        CurrentHealth = MaxHealth;
    }

    abstract protected String getCharacterClass();

    @Override
    public String toString() {
        return "CurrentHealth = '" + CurrentHealth + '\'' +
                ", CharacterClass='" + getCharacterClass() + '\'' +
                '}';
    }

    void pick(Item newItem) throws Exception {
        if(inventory.size() < 10){
            inventory.add(newItem);
            if (newItem instanceof Equippable && hotBar.size() < 3) {
                hotBar.add(newItem);
                return;
            }
        }

        throw new Exception("No space in inventory");

    }

    void useAt(int index, Character target) {
        Item item = hotBar.get(index);

        if (item instanceof Consumable) {
            if (item instanceof Potion) {
                ((Potion) item).consume(this);
            }
        }

        if (item instanceof Usable) {
            if (item instanceof Cat) {
                ((Cat) item).use(this, target);
            }
            if (item instanceof Scroll) {
                ((Scroll) item).use(this, target);
            }
        }
        hotBar.remove(index);
        inventory.remove(index);

        for (Item itemm : inventory) {
            if (itemm instanceof Equippable) {
                inventory.add(itemm);
                return;
            }
        }
    }
}
