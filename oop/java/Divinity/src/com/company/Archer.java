package com.company;

public class Archer extends Character{
    public Archer() {
        setDextirity(10);
        setIntelligence(5);
        setMaxHealth(100);
        setCurrentHealth(100);
    }

    @java.lang.Override
    protected String getCharacterClass() {
        return "Archer";
    }
}
