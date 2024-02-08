import java.util.Arrays;

public class Array {
    public static void main(String[] args) {
        int[] numbers = new int[5]; 
        numbers[0] = 1;
        numbers[1] = 2;
        numbers[2] = 3;
        numbers[3] = 4;
        numbers[4] = 5;
        System.out.println(Arrays.toString(numbers));

        int[] numbers1 = { 1, 2, 3, 4, 5 };
        System.out.println(numbers1.length); //returns 5
        Arrays.sort(numbers1); //sorts the array in ascending order

        // multi-dimensional arrays:
        int[][] matrix = new int[2][3];
        int[][] matrix2 = { {1, 2, 3}, {3, 4, 5} }; //create a matrix like this as well
        matrix[0][0] = 1;
        System.out.println(Arrays.deepToString(matrix2)); //return [[1, 0, 0], [0, 0, 0]]
    }
}
