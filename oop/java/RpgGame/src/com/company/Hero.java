package com.company;

public class Hero {
    String name;
    Equip equipW = new Equip();
    Bag bag = new Bag();

    void equipItem(Item item) throws Exception{
        if (item instanceof Weapon) {
            for (int i = 0; i < equipW.weapons.length; i++) {
                if (equipW.weapons[i] == null){
                    equipW.weapons[i] = (Weapon) item;
                    return;
                }
            }
            throw new Exception("Full W");

        }

        if (item instanceof Armour) {
            for (int i = 0; i < equipW.armour.length; i++) {
                if (equipW.armour[i] == null) {
                    equipW.armour[i] = (Armour) item;
                    return;
                }
            }
            throw new Exception("Full A");

        }

        if (item instanceof Potion) {
            for (int i = 0; i < equipW.potions.length; i++) {
                if (equipW.potions[i] == null) {
                    equipW.potions[i] = (Potion) item;
                    return;
                }
            }
            throw new Exception("Full P");
        }
    }

    void pickUpItem(Item item) throws Exception{
        for (int i = 0; i < bag.items.length; i++) {
            if(bag.items[i] == null) {
                bag.items[i] = item;
                return;
            }
        }
        throw new Exception("Full bag");
    }

}
