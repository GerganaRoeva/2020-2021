package com.company;

public class Mage extends Character{
    private int MaxMana;
    private int CurrentMana;

    public Mage() {
        MaxMana = 80;
        CurrentMana = MaxMana;
        setDextirity(5);
        setIntelligence(10);
        setMaxHealth(60);
        setCurrentHealth(60);
    }

    public int getMaxMana() {
        return MaxMana;
    }

    public int getCurrentMana() {
        return CurrentMana;
    }

    public void setCurrentMana(int currentMana) {
        CurrentMana = currentMana;
    }

    @java.lang.Override
    protected String getCharacterClass() {
        return "Mage";
    }
}
