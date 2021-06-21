package com.company;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

public class Order {
    private int id;
    private HashMap<Dish, Double> dishes = new HashMap<Dish, Double>();

    public Order(int id, HashMap<Dish, Double> dishes) {
        this.id = id;
        this.dishes = dishes;
    }

    public int getId() {
        return id;
    }

    public HashMap<Dish, Double> getDishes() {
        return dishes;
    }

    boolean getFromStorage(Storage storage){
        HashMap<Product, Double> needMap = new HashMap<>();
        for (Map.Entry<Dish, Double> entry : dishes.entrySet()) {
            HashMap<Product, Double> innerMap = entry.getKey().getProducts();
            for(Map.Entry<Product, Double> inner : innerMap.entrySet()){
                for(Map.Entry<Product, Double> need : needMap.entrySet()){
                    if(needMap.containsKey(inner.getKey())){
                        double newVal = inner.getValue() + need.getValue();
                        need.setValue(newVal);
                    }
                    else needMap.put(inner.getKey(), inner.getValue());
                }
            }
        }

        for(Map.Entry<Product, Double> storageMap : storage.getProducts().entrySet()){
            for (Map.Entry<Product, Double> need : needMap.entrySet()){
                if(storage.getProducts().containsKey(need.getKey())){
                    if(storageMap.getValue() < need.getValue()){
                        return false;
                    }
//                    else storage.getProduct(need.getKey(), need.getValue());
                }
                else return false;
            }
        }

        return true;
    }

    @Override
    public String toString() {
        return "Order{" +
                "id=" + id +
                ", dishes=" + dishes.toString() +
                '}';
    }
}
