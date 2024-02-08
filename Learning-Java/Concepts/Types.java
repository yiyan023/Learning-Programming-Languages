import java.awt.*;

public class Types {
    public static void main(String[] args) {
        // primitive types -- do not change the other object 
        int object1 = 1;
        int object2 = object1;
        object1 = 2;
        System.out.println(object2); // will return 1

        // reference types -- will change the other object
        Point point1 = new Point(1, 1);
        Point point2 = point1;
        point1.x=2;
        System.out.println(point2); // will return (2, 1)

    }
}
