package com.company;

import java.util.*;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

import static java.lang.Thread.sleep;

public class Chef implements Runnable {
    private String name;
    private Restaurant restaurant;
    private List<Order> startedCooking = new ArrayList<>();

    public Chef(String name, Restaurant restaurant) {
        this.name = name;
        this.restaurant = restaurant;
    }

    @Override
    public void run() {
        Lock lock = new ReentrantLock();
//        while (true) {
        if (!restaurant.getActiveOrders().isEmpty()){
            Iterator<Order> itr = restaurant.getActiveOrders().iterator();
            while (itr.hasNext()){
                Order order = itr.next();
                startedCooking.add(order);

                try {
                    if (lock.tryLock(1, TimeUnit.SECONDS)) {
                        try {
                            itr.remove();
                        } finally {
                            lock.unlock();
                        }
                    }
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }


                boolean checkPrice = false;

                double fullPrice = 0;
                int fullTimeForCooking = 0;

                for (Map.Entry<Dish, Double> entry : order.getDishes().entrySet()) {
                    fullPrice += entry.getValue() * entry.getKey().getSalePrice();
                    fullTimeForCooking += entry.getValue() * entry.getKey().getTimeToCook();
                }

                try {
                    if (fullPrice <= restaurant.getMoney()) {
                        if (lock.tryLock(1, TimeUnit.SECONDS)) {
                        try {
                                checkPrice = true;
                                restaurant.setMoney(restaurant.getMoney() - fullPrice);
                        } finally {
                            lock.unlock();
                        }
                        }
                    } else System.out.println("money for this order not enough");

                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                if (order.getFromStorage(restaurant.getStorage())){

                    for(Map.Entry<Dish, Double> entry : order.getDishes().entrySet()) {
                        for (Map.Entry<Product, Double> products : entry.getKey().getProducts().entrySet()){
                            try {
                                if(lock.tryLock(1, TimeUnit.SECONDS)) {
                                    try {
                                        restaurant.getStorage().getProduct(products.getKey(), products.getValue());
                                    }finally { lock.unlock(); }
                                    }
                            } catch (InterruptedException e) {
                                e.printStackTrace();
                            }
                        }
                    }
                    System.out.println("Get products");

                }

                try {
                    if(!order.getFromStorage(restaurant.getStorage()) || !checkPrice)
                        if(lock.tryLock(1, TimeUnit.SECONDS)) {
                        try {
                                restaurant.failOrder(restaurant.getActiveOrders().get(0));
                                System.out.println("order failed");
                                continue;
                        }
                        finally { lock.unlock(); }
                    }
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }

                System.out.println("cooking...");

                try {
                    TimeUnit.SECONDS.sleep(fullTimeForCooking);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }

                System.out.println("cooked");

                try {
                    if (lock.tryLock(1, TimeUnit.SECONDS))
                        try {
                            restaurant.addCompleteOrder(order);
                            System.out.println(order.toString());
                            System.out.println("Completed : " + restaurant.getCompletedOrders().toString());
                            System.out.println("Active :    " + restaurant.getActiveOrders().toString());

                            System.out.println("completed");
                        } finally {
                            lock.unlock();
                        }
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}


//    @Override
//    public void run() {
////        System.out.println("in run");
//        Lock lock = new ReentrantLock();
//        if (!restaurant.getActiveOrders().isEmpty()){
//            boolean checkPrice = false;
//            boolean checkProducts = false;
//
//            double fullPrice = 0;
//            int fullTimeForCooking = 0;
//
//            for (Map.Entry<Dish, Double> entry : restaurant.getActiveOrders().get(restaurant.getChefs().size() - 1).getDishes().entrySet()) {
//                fullPrice += entry.getValue() * entry.getKey().getSalePrice();
//                fullTimeForCooking += entry.getValue() * entry.getKey().getTimeToCook();
//            }
//
//            try {
//                if(lock.tryLock(1, TimeUnit.SECONDS)) {
//                    try {
//                        if(fullPrice <= restaurant.getMoney()){
//                            checkPrice = true;
//                            restaurant.setMoney(restaurant.getMoney() - fullPrice);
////                            System.out.println("money-");
//                        }
//                    } finally { lock.unlock(); }
//                }
//            } catch (InterruptedException e) { e.printStackTrace(); }
//
//
//            if (restaurant.getActiveOrders().get(0).getFromStorage(restaurant.getStorage())){
//                System.out.println("Get products");
//                checkProducts = true;
//            }
//            try {
//                if(lock.tryLock(1, TimeUnit.SECONDS)) {
//                    try {
//                        if(!checkPrice || !checkProducts)
//                            restaurant.failOrder(restaurant.getActiveOrders().get(0));
//                    }
//                    finally { lock.unlock(); }
//                }
//                try {
//                    System.out.println("cooking...");
//
//                    TimeUnit.SECONDS.sleep(fullTimeForCooking);
//                }
//                catch (InterruptedException e) {e.printStackTrace();}
//                System.out.println("cooked");
//
//                try {
//                    if (lock.tryLock(1, TimeUnit.SECONDS))
//                        try {
//                            System.out.println(restaurant.getActiveOrders().get(0).getDishes().size());
//
//                            restaurant.completeOrder(0);
//                        } finally {
//                            lock.unlock();
//                        }
//                }catch (Exception exo){};
//
//            }
//            catch (InterruptedException e) { e.printStackTrace(); }
//        }
//}
//
//
//
