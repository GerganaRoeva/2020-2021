package com.company;
import java.util.List;

public abstract class Hero
{
    protected int level;
    protected int power;
    protected int intelligence;
    protected String specialty;

    public Hero(int level, int power, int intelligence, String specialty)
    {
        this.level = level;
        this.power = power;
        this.intelligence = intelligence;
        this.specialty = specialty;
    }

    abstract double getPower(List<Hero> party, Monster monster);

}
