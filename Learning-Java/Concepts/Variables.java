import java.util.Date;

public class Variables { 
    public static void main(String[] args) {
        
        int age = 30, temperature = 20; // only processes integers 
        // you can declare multiple variables on the same line
        byte age2 = 30; // more efficient
        double BMI = 20.1;
        char Name = 'A'; // not String
        boolean Yes = true;

        System.out.println(age);
        System.out.println(age2);
        System.out.println(BMI);
        System.out.println(Name);
        System.out.println(Yes);
        System.out.println(temperature);

        // reference types 
        Date now = new Date();
        System.out.println(now); // returns current date

        //constants -- add final in front of it
        final double pi = 3.14; //will not be able to change after this
        System.out.println(pi);
    }
}