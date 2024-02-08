public class Strings {
    public static void main(String[] args) {
        String Message = "Hello!";
        System.out.println(Message); //returns "Hello!"
        System.out.println(Message.endsWith("Hello!")); // returns true
        System.out.println(Message.startsWith("Hello!")); //also returns true
        System.out.println(Message.length()); // returns 6
        System.out.println(Message.indexOf("H")); //returns 0
        System.out.println(Message.replace("H", "X")); // returns Xello!
    }
}
