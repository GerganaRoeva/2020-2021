package com.company;
//        Зеленчук
//        всеки ден се нуждае от поливане с Лейка
//        когато стане готово за бране се нуждае от мотика за изкопаване
//        расте 2 дни
public class Vegetables extends Sowing{
    private int needWater = 1;

    public Vegetables(String name) {
        super(name, 4, 0);
    }
}
