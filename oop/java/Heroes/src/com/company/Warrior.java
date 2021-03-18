package com.company;
import java.util.List;
import java.util.ArrayList;

public class Warrior extends Hero
{
    public Warrior(int level, int power, int intelligence, String specialty) {
        super(level,  power, intelligence, specialty);
    }

    @Override
    double getPower(List<Hero> party, Monster monster)
    {
        double output= 0;

        if (this.specialty == "Knight") {
            int clericCounter = 0;
            for (Hero member : party) {
                if (member.specialty == "Cleric") clericCounter++;
            }
            output = this.power * level + clericCounter * (0.25 * this.power);
        } else if (this.specialty == "Barbarian") {
            output = power * level;
        }
        return output;
    }
}
