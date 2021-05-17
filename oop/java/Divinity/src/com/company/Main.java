package com.company;

public class Main {

    public static void main(String[] args) {
        Mage Andromed = new Mage();
        Archer Hristo = new Archer();

        Cat magicCat = new Cat();
        Scroll scroll = new Scroll(5);
        Potion potionForMage = new Potion(0, 5);

        try {
            Hristo.pick(scroll);

            Andromed.pick(magicCat);
            Andromed.pick(potionForMage);
        } catch (Exception e) {
            System.out.println("No space in inventory");
        }

        System.out.println("Andromed mana: " + Andromed.getCurrentMana());
        System.out.println("Andromed health: " + Andromed.getCurrentHealth());
        System.out.println("Hristo health: " + Hristo.getCurrentHealth());

        Hristo.useAt(0, Andromed);

        System.out.println("Andromed mana: " + Andromed.getCurrentMana());
        System.out.println("Andromed health: " + Andromed.getCurrentHealth());
        System.out.println("Hristo health: " + Hristo.getCurrentHealth());

        Andromed.useAt(0, Hristo);

        System.out.println("Andromed mana: " + Andromed.getCurrentMana());
        System.out.println("Andromed health: " + Andromed.getCurrentHealth());
        System.out.println("Hristo health: " + Hristo.getCurrentHealth());


    }
}
