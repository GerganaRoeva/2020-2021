package com.company;

public class Product {
    private String name;
    private String unit;
    private double price;

    public Product(String name, String unit, double price) {
        this.name = name;
        this.unit = unit;
        this.price = price;
    }

    public double getPrice() {
        return price;
    }
}
