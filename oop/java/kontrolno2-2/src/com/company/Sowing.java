package com.company;
//Общо за всички посеви:
//        име
//        нужна възраст(в брой дни) докато стане готово за бране
//        текуща възраст(в брой дни)
//        флагове за това дали е обран или мъртъв
//        Когато бъде обран от земеделецът се вдига съответният флаг на посева.
//        Ако посев не бъде обран в рамките на 2 дни след като стане готов той умира и се вдига съответният флаг.
//        Обран или мъртъв посев повече не може да бъде обран.
public class Sowing {
    private String name;
    private int needDays;
    private int currentDays;
    private boolean isSelected;
    private boolean isDead;
    private boolean isWatered;

    public Sowing() {}

    public Sowing(String name, int needDays, int currentDays) {
        this.name = name;
        this.needDays = needDays;
        this.currentDays = 0;
        this.isSelected = false;
        this.isDead = false;
        this.isWatered = false;
    }

    public void setWatered(boolean watered) {
        isWatered = watered;
    }

    public void setSelected(boolean selected) {
        isSelected = selected;
    }

    public String getName() {
        return name;
    }

    public int getCurrentDays() {
        return currentDays;
    }

    public boolean isSelected() {
        return isSelected;
    }

    public void setCurrentDays(int currentDays) {
        this.currentDays = currentDays;
    }

    public void addDay() {
        this.currentDays = currentDays + 1;
    }

    @java.lang.Override
    public java.lang.String toString() {
        return "Sowing{" +
                "name='" + name + '\'' +
                '}';
    }

    public boolean getIsDead() {
        return isDead;
    }

    public boolean isWatered() {
        return isWatered;
    }

    public void chek(){
        if(isSelected == false && needDays > currentDays){
            isDead = true;
        }
    }

}
