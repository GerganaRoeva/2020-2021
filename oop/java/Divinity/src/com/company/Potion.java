package com.company;

public class Potion extends Item implements Equippable, Consumable{
    private int HealthToRecover;
    private int ManaToRecover;

    public Potion(int healthToRecover, int manaToRecover) {
        HealthToRecover = healthToRecover;
        ManaToRecover = manaToRecover;
    }

    @java.lang.Override
    public void consume(Character target) {
        if(target.getCharacterClass() == "Archer") {
            int NewHealth = (int) target.getCurrentHealth() + HealthToRecover;
            if (NewHealth > target.getMaxHealth()) {
                NewHealth = target.getMaxHealth();
            }
            target.setCurrentHealth(NewHealth);
        }
        if(target.getCharacterClass() == "Mage")
        {
            int NewMana = ((Mage) target).getCurrentMana() + ManaToRecover;
            if (NewMana > ((Mage) target).getMaxMana()) {
                NewMana = ((Mage) target).getMaxMana();
            }
            ((Mage) target).setCurrentMana(NewMana);
        }
    }
}
