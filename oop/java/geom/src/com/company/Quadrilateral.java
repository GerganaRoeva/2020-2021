package com.company;

public class Quadrilateral extends Shape {
    Point lowerLeft;
    Point upperRight;

    public Quadrilateral(Point lowerLeft, Point upperRight) {
        this.lowerLeft = lowerLeft;
        this.upperRight = upperRight;
    }

}
