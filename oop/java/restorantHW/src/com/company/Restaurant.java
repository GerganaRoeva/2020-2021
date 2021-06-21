package com.company;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class Restaurant {
    private List<Dish> dishes = new ArrayList<>();
    private List<Waiter> waiters = new ArrayList<>();
    private List<Chef> chefs = new ArrayList<>();
    private Storage storage;
    private double money;
    private List<Order> activeOrders = new ArrayList<>();
    private List<Order> completedOrders = new ArrayList<>();
    private List<Order> failedOrders = new ArrayList<>();

    public Restaurant(List<Dish> dishes, Storage storage, double money) {
        this.dishes = dishes;
        this.storage = storage;
        this.money = money;
    }

    public List<Chef> getChefs() {
        return chefs;
    }

    public double getMoney() {
        return money;
    }

    public void setMoney(double money) {
        this.money = money;
    }

    public List<Order> getActiveOrders() {
        return activeOrders;
    }

    public List<Order> getCompletedOrders() {
        return completedOrders;
    }

    public Storage getStorage() {
        return storage;
    }

    void addChef(Chef chef){
        chefs.add(chef);
    }

    void addWaiter(Waiter waiter){
        waiters.add(waiter);
    }

    void addOrder(Order newOrder){
        int countDishes = 0;
        int countValidDishes = 0;
        for (Map.Entry<Dish, Double> dishMapR: newOrder.getDishes().entrySet()) {
            countDishes += 1;
        }
        for (Map.Entry<Dish, Double> dishMapR: newOrder.getDishes().entrySet()){
            for (Dish dish : dishes) {
                if(dishMapR.getKey().getName().equals(dish.getName())){
                    countValidDishes += 1;
                }
            }
        }
        if (countDishes == countValidDishes )
        activeOrders.add(newOrder);
        else System.out.println("Order conteins invalid dish");
    }

    void removeOrder(Order order){
        activeOrders.remove(order);
    }

    void completeOrder(int id){
        for (Order order : activeOrders)
            if(order.getId() == id) {
                completedOrders.add(order);
                removeOrder(order);
            }
    }

    void addCompleteOrder(Order order){
        completedOrders.add(order);
    }

    void failOrder(Order order){
        failedOrders.add(order);
        activeOrders.remove(order);
    }

    @Override
    public String toString() {
        return "Restaurant{" +
                "completedOrders=" + completedOrders.toString() +
                '}';
    }
}
