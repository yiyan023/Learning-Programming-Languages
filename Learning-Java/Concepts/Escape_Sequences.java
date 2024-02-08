public class Escape_Sequences {
    public static void main(String[] args) {
        String Message = "Hello!\n My name is Yiyan!"; // \n creates another line
        System.out.println(Message); 
        String Message2 = "Hello \"Bobby\"";
        System.out.println(Message2); // returns Hello "Bobby"
        String Message3 = "c:\\Windows\\"; 
        System.out.println(Message3); //returns "c:\Windows\"
        String Message4 = "Hello!\t My name is Yiyan!"; // adds a table
        System.out.println(Message4);
    }
}
