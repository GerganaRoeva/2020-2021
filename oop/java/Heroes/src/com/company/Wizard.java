package com.company;

import java.util.List;

public class Wizard extends Hero{
    public Wizard(int level, int power, int intelligence, String special) {
        super(level,  power, intelligence, special);

    }

    @Override
    double getPower(List<Hero> party, Monster monster) {
        int d = 0, e = 0, s = 0, h = 0;
        int power = this.level * this.intelligence;

        for(int i =0; i < monster.traits.size(); i++) {
            String trait = monster.traits.get(i);

            if (trait == "Darkness") {
                d += 1;
                e += 1;
                s += 1;
                h += 1;
            } else if (trait == "Evil") {
                e += 1;
                s += 1;
                h += 1;
            } else if (trait == "Summoned") {
                s += 1;
                h += 1;
            } else if (trait == "Holy") {
                h += 1;
            }
        }

        if (this.specialty == "Cleric") {
            power += (d + e) * (1 / 4) * power;
            power += (s + e) * (1 / 4) * power;
            power += h * (1 / 4) * power;
        } else if (this.specialty == "Sorcerer") {
            power += (s + e) * (1 / 4) * power;
            power += h * (1 / 4) * power;
        } else if (this.specialty == "Warlock") {
            power += h * (1 / 4) * power;
        }

        return power;
    }
}