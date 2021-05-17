package com.company;

public class Cat extends Item implements Equippable, Usable{

    int damage;
    public Cat() {
        damage = 5;
    }

    @java.lang.Override
    public void use(Character source, Character target) {
        target.setCurrentHealth(target.getCurrentHealth() - damage);
    }
}
