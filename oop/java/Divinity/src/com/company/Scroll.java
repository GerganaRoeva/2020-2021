package com.company;

//- клас Scroll, който имплементира прикачените интерфейси Equippable & Usable, с поле за базовия damage (int), който прави магията.
// При използване на scroll-a за всяка 1 точка разлика в умението intelligence на двамата герои базовият damage се модифицира с 10%.
// Т.е: при базов damage 10, caster intelligence 8 & target intelligence 12 - крайният резултат e взети 6 health на target-a.

public class Scroll extends Item implements Equippable, Usable{

    private int damage;

    public Scroll(int damage) {
        this.damage = damage;
    }

    @java.lang.Override
    public void use(Character source, Character target) {
        target.setCurrentHealth(target.getCurrentHealth() - (damage - (1/10)*damage*(target.getIntelligence() - source.getIntelligence())));
    }
}
