package com.company;
import java.util.*;

public class Race {
    private List<Car> Cars = new ArrayList<>();
    private int lapsCount;
    private List<Float> segments = new ArrayList<>();

    private List<Car> fabricCars = new ArrayList<>();
    private int fabricLapsCount;
    private List<Float> fabricSegments = new ArrayList<>();

    public Race(List<Car> cars, int lapsCount, List<Float> segments) {
        Cars = cars;
        this.lapsCount = lapsCount;
        this.segments = segments;

        fabricCars = cars;
        this.fabricLapsCount = lapsCount;
        this.fabricSegments = segments;
    }

    void addCar(Car newCar){
        Cars.add(newCar);
    }

    void chagePath(int newLapsCount, List<Float> newSegments) {
        this.lapsCount = lapsCount;
        this.segments = segments;
    }

    void reset(){
        Cars = fabricCars;
        this.lapsCount = fabricLapsCount;
        this.segments = fabricSegments;
    }
}

// вижте аз пиша малко, за да нямате много за проверяване после
