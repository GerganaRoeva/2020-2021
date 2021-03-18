package com.company;
import java.util.List;

public abstract class Shape {
    Point center;

    abstract List<Point> getPoints();
    abstract boolean checkCollision(Shape other);

}
