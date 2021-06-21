package com.company;

import java.util.Iterator;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

//проверяват дали всички ястия за дадена поръчка са сготвени. Ако са сготвени, те завършват поръчката като извикват метода в ресторанта.
public class Waiter implements Runnable {
    private String name;
    private Restaurant restaurant;

    public Waiter(String name, Restaurant restaurant) {
        this.name = name;
        this.restaurant = restaurant;
    }

    @Override
    public void run() {
        Lock lock = new ReentrantLock();
        while (true) {if (!restaurant.getCompletedOrders().isEmpty()) break;}
//        if (!restaurant.getCompletedOrders().isEmpty()){
        Iterator<Order> itr = restaurant.getCompletedOrders().iterator();
        while (itr.hasNext()){
            Order order = itr.next();
            try {
                if (lock.tryLock(1, TimeUnit.SECONDS)) {
                    try {
                        System.out.println("Waiter working...");
                        itr.remove();
                    } finally {
                    lock.unlock();
                }
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            try {
                System.out.println();
                TimeUnit.SECONDS.sleep(2);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("waiter finished.");
        }
    }
}




//    @Override
//    public void run() {
//        Lock lock = new ReentrantLock();
//        System.out.println("waiter run");
//
//        while(true) {
//            if (!restaurant.getCompletedOrders().isEmpty())
//                System.out.println("not empty");
//            for (Order order : restaurant.getCompletedOrders()) {
//
//                try {
//                    if (lock.tryLock(1, TimeUnit.SECONDS)) {
//                        try {
//                            restaurant.getCompletedOrders().remove(order);
//                            System.out.println("Waiter working...");
//                        } finally {
//                            lock.unlock();
//                        }
//                    }
//                } catch (InterruptedException e) {
//                    e.printStackTrace();
//                }
//
//                try {
//                    System.out.println();
//                    TimeUnit.SECONDS.sleep(2);
//                } catch (InterruptedException e) {
//                    e.printStackTrace();
//                }
//                System.out.println("waiter finished.");
//            }
//        }
//    }
//}
