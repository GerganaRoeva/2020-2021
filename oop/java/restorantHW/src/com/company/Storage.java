package com.company;

import java.util.HashMap;
import java.util.Map;


public class Storage {
    private HashMap<Product, Double> products = new HashMap<Product, Double>();

    public Storage() {}

    void addProduct(Product product, Double amount) {
        if (products.containsKey(product)){
            for (Map.Entry<Product, Double> entry : products.entrySet())
                if(entry.getKey() == product)
                    products.replace(product, amount + entry.getValue());
        }
        else products.put(product, amount);
    }

    public HashMap<Product, Double> getProducts() {
        return products;
    }

    void getProduct(Product product, Double amount) {
        for (Map.Entry<Product, Double> entry : products.entrySet())
            if(entry.getKey() == product){
                Double newAmount =  entry.getValue() - amount;
                if(newAmount < 0) throw new IllegalArgumentException(" ");
                if(newAmount == 0) products.remove(product);
                else products.replace(product, newAmount);
            }
    }
}

