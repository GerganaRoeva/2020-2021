package com.company;

//        Плод
//        всеки ден се нуждае от поливане с Лейка
//        когато стане готово за бране се нуждае от Стълба за качване
//        расте 4 дни

public class Fruit extends Sowing{
    private int needWater = 1;

    public Fruit(String name) {
        super(name, 4, 0);
    }
}
