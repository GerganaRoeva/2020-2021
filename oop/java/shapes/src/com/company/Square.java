package com.company;
import java.util.List;
import java.util.ArrayList;


public class Square extends Shape {
    Point center;
    int d;

    List<Point> getPoints() {
        Point A = new Point();
        A.x = center.x + d;
        A.y = center.y + d;

        Point B = new Point();
        B.x = center.x + d;
        B.y = center.y - d;

        Point C = new Point();
        C.x = center.x - d;
        C.y = center.y - d;

        Point D = new Point();
        D.x = center.x - d;
        D.y = center.y + d;

        List<Point> points = new ArrayList<Point>();
        points.add(0, A);
        points.add(1, B);
        points.add(2, C);
        points.add(3, D);

        return points;




    }

    boolean checkCollision(Shape other) {
        return true;
    }
}
