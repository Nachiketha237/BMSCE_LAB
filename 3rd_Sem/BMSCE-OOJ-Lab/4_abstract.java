import java.util.*;
import java.lang.Math;

abstract class Shape{
    abstract double area();
    abstract double perimeter();
}

class Rectangle extends Shape {
    private double _l, _b;

    Rectangle(double x, double y) {
        _l = x;
        _b = y;
    }

    double area() {
        return _l * _b;
    }

    double perimeter() {
        return (_l + _b) * 2;
    }
}

class Circle extends Shape {
    private double _r;

    Circle(double x) {
        _r = x;
    }

    double area() {
        return Math.PI * _r * _r;
    }

    double perimeter() {
        return 2 * Math.PI * _r;
    }
}

class Triangle extends Shape {
    private double _s1, _s2, _s3;

    Triangle(double x, double y, double z) {
        _s1 = x;
        _s2 = y;
        _s3 = z;
    }

    double area() {
        double s = this.perimeter()/2;

        System.out.println("Area is " + Math.sqrt(s*(s-_s1)*(s-_s2)*(s-_s3)));

        return Math.sqrt(s * (s-_s1) * (s-_s2) * (s-_s3));
    }

    double perimeter() {
        return _s1+_s2+_s3;
    }
}

class Main {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the length and breadth of Rectangle: ");
        Rectangle r1 = new Rectangle(sc.nextInt(), sc.nextInt());

        System.out.println("Enter the 3 sides of Triangle: ");
        Triangle t1 = new Triangle(sc.nextInt(), sc.nextInt(), sc.nextInt());

        System.out.println("Enter the radius of Cicle: ");
        Circle c1 = new Circle(sc.nextInt());

        System.out.println("Area of Rectangle: " + r1.area());
        System.out.println("Perimeter of Rectangle: " + r1.perimeter());

        System.out.println("Area of Triangle: " + t1.area());
        System.out.println("Perimeter of Triangle: " + t1.perimeter());

        System.out.println("Area of Circle: " + c1.area());
        System.out.println("Perimeter of Circle: " + c1.perimeter());        
    }
}
