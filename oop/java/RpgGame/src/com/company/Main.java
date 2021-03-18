package com.company;

public class Main {

    public static void main(String[] args) throws Exception {
        System.out.println("hihi");

        Weapon wep1 = new Weapon();
        wep1.name = "karsiv noj";
        wep1.damage = 10;

        Armour arm1 = new Armour();
        arm1.name = "mn hybava bronq";
        arm1.defense = 30;

        Armour arm2 = new Armour();
        arm2.name = "hybava bronq";
        arm2.defense = 15;

        Potion pos1 = new Potion();
        pos1.name = "pravi vsi4ko rozovo";

        Potion pos2 = new Potion();
        pos2.name = "pravi vsi4ko 4erno";

        Weapon[] wepons = new Weapon[2];
        Armour[] armours = new Armour[4];
        Potion []potions = new Potion[6];

        Hero player1 = new Hero();
        player1.name = "Adromed";

        player1.equipItem(wep1);
        player1.equipItem(arm1);
        player1.equipItem(arm2);
        player1.equipItem(pos1);

        player1.pickUpItem(pos2);




    }
}
