package com.company;
import java.util.*;

public class Car {
    private int currPos;
    private String driverName;
    private int currLap;
    private List<Float> timesForSegm = new ArrayList<>();
    private List<Float> timesForLap = new ArrayList<>();

    public Car(String driverName) {
        this.driverName = driverName;
        currPos = 1;
        this.currLap = 0;
    }

    public Car(String driverName, int currPoss) {
        this.currPos = currPos;
        this.driverName = driverName;
        this.currLap = 0;

    }

}
