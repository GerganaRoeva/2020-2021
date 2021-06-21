package com.company;

import org.w3c.dom.ls.LSInput;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.concurrent.TimeUnit;

public class Main {

    public static void main(String[] args) throws InterruptedException {
        Product domat = new Product("domat", "kg", 0.5);
        Product sirene = new Product("sirene", "kg", 0.6);
        Product maslini = new Product("maslini", "kg", 10);
        Product voda = new Product("voda", "liter", 5);
        Product fide = new Product("fide", "kg", 0.5);
        Product pileshko = new Product("pileshko", "kg", 10);


        HashMap<Product, Double> forSalata = new HashMap<>();
        forSalata.put(domat, 2.0);
        forSalata.put(sirene, 0.5);

        HashMap<Product, Double> forSupa = new HashMap<>();
        forSupa.put(voda, 1.0);
        forSupa.put(fide, 0.5);
        forSupa.put(pileshko, 0.5);

        HashMap<Product, Double> forGarnitura = new HashMap<>();
        forGarnitura.put(maslini, 0.4);


        Dish salata = new Dish("Salata", forSalata, 3);
        Dish supa = new Dish("supa", forSupa, 1);
        Dish garnitura = new Dish("garnitura", forGarnitura, 2);

        List<Dish> dishes = new ArrayList<>();
        dishes.add(salata);
        dishes.add(supa);
        dishes.add(garnitura);

        HashMap<Dish, Double> forOrder1 = new HashMap<>();
        forOrder1.put(supa, 2.0);
        forOrder1.put(salata, 1.0);

        Order order1 = new Order(0, forOrder1);


        HashMap<Dish, Double> forOrder2 = new HashMap<>();
        forOrder2.put(garnitura, 1.0);
//        forOrder2.put(salata, 2.0);

        Order order2 = new Order(0, forOrder2);


        Storage storage = new Storage();
        storage.addProduct(domat, 200.0);
        storage.addProduct(sirene, 1000.0);
        storage.addProduct(maslini, 100.0);
        storage.addProduct(fide, 300.0);
        storage.addProduct(voda, 1000.0);
        storage.addProduct(pileshko, 400.0);


        Restaurant restaurant = new Restaurant(dishes, storage, 1000.0);
        Chef chef1 = new Chef("Pesho", restaurant);
        Chef chef2 = new Chef("Andromed", restaurant);

        Waiter waiter1 = new Waiter("Alkira", restaurant);
        Waiter waiter2 = new Waiter("Dari", restaurant);

        restaurant.addChef(chef1);
        restaurant.addChef(chef2);
        restaurant.addWaiter(waiter1);
        restaurant.addWaiter(waiter2);

        restaurant.addOrder(order1);
        restaurant.addOrder(order2);

        Thread cooker1 = new Thread(chef1);
        Thread cooker2 = new Thread(chef1);
        Thread waiter11 = new Thread(waiter2);
        Thread waiter22 = new Thread(waiter2);
        System.out.println(order1.toString());
        System.out.println(order2.toString());

        System.out.println("Start");
        cooker1.start();
        TimeUnit.SECONDS.sleep(2);
        cooker2.start();
        TimeUnit.SECONDS.sleep(2);

        waiter11.start();
 //        System.out.println(restaurant.getCompletedOrders().toString());
        TimeUnit.SECONDS.sleep(2);

        waiter22.start();


//        boolean flag = true;
////        while(flag) {
////            if (restaurant.getActiveOrders().isEmpty() && restaurant.getCompletedOrders().isEmpty())
////                flag = false;
////        }


    }
}
