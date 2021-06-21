package com.company;

import java.util.HashMap;
import java.util.Map;

public class Dish {
    private String name;
    private HashMap<Product, Double> products = new HashMap<Product, Double>();
    private int timeToCook;
    private boolean ready = false;

    public Dish(String name, HashMap<Product, Double> products, int timeToCook) {
        this.name = name;
        this.products = products;
        this.timeToCook = timeToCook;
    }

    public String getName() {
        return name;
    }

    float getSalePrice(){
        float price = 0;
        for (Map.Entry<Product, Double> entry : products.entrySet())
            price += entry.getValue()*entry.getKey().getPrice();
        return 2*price;
    }

    public HashMap<Product, Double> getProducts() {
        return products;
    }

    public int getTimeToCook() {
        return timeToCook;
    }

    @Override
    public String toString() {
        return "Dish{" +
                "name='" + name + '\'' +
                '}';
    }
}
