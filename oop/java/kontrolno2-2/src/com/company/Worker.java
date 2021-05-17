package com.company;
import java.util.*;

//Замеделецът има име и списък от наличните му инструменти. Освен тях добавете и каквито методи и допълнителни атрибути
//        сметнете за нужно(чети надолу).
public class Worker {
    String name;
    List<String> tools = new ArrayList<>();

    public Worker(String name) {
        this.name = name;
    }

    public void addTools(String tool) {
        tools.add(tool);
    }

    public void water(Sowing sowing) {
        sowing.setWatered(true);
    }

    public void brane(Sowing sowing) {
        sowing.setSelected(true);

    }

    public void allWork(Sowing sowing) {
        if (tools.indexOf("lejka") != -1) {
            if (sowing instanceof Fruit || sowing instanceof Vegetables) {
                water(sowing);
            }
        }

        if (tools.indexOf("stulba") != -1) {
            if (sowing instanceof Fruit) {
                brane(sowing);
            }
        }

        if (tools.indexOf("motika") != -1) {
            if (sowing instanceof Vegetables) {
                brane(sowing);
            }
        }

        if (tools.indexOf("rukavici") != -1) {
            if (sowing instanceof Cactus) {
                brane(sowing);
            }
        }

        if(sowing.isSelected() && sowing.isWatered())
        {
            sowing.setCurrentDays(0);
        }





    }
}