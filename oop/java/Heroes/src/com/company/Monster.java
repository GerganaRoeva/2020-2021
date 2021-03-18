package com.company;
import java.util.List;
import java.util.ArrayList;
//import java.lang.String;

public class Monster {
    int level;
    int power;
    String name;
    List<String> traits;

    public Monster(int level, int power, String name, List<String> traits) {
        this.level = level;
        this.power = power;
        this.name = name;
        this.traits = traits;
    }

    double getPower(List<Hero> party) {
        int fight_power = power*level;
        int counter = 0;

        if (name == "Darkness") {
            for (Hero member : party) {
                if (member.specialty == "Cleric") counter++;
            }
            return (power * level + counter * (0.25 * power * level));
        } else if (name == "Evil") {
            for (Hero member : party) {
                if (member.specialty == "Knight" || member.specialty == "Monk") counter++;
            }
            return (power * level + counter * (0.25 * power * level));
        } else if (name == "Summoned") {
            for (Hero member : party) {
                if (member.specialty == "Barbarian") counter++;
            }
            return (power * level + counter * (0.25 * power * level));
        } else if (name == "Holy") {
            for (Hero member : party) {
                if (member.specialty == "Warlock") counter++;
            }
            return (power * level + counter * (0.25 * power * level));
        }

        return power*level;
    }

}
