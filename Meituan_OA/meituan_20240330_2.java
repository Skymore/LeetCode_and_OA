import java.util.Scanner;

public class meituan_20240330_2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading input strings
        String s = scanner.nextLine();
        String t = scanner.nextLine();
        int length = s.length();
        int index = -1;

        // Finding the first index from the end where the two strings differ
        for (int i = length - 1; i >= 0; i--) {
            if (s.charAt(i) != t.charAt(i)) {
                index = i;
                break;
            }
        }

        // If no differences are found, output 0 and terminate
        if (index == -1) {
            System.out.println("0");
            return;
        }

        // Determining if the remaining parts of the strings are uniform
        boolean sUniform = true;
        boolean tUniform = true;
        for (int i = index; i >= 0; i--) {
            if (s.charAt(i) != s.charAt(index)) {
                sUniform = false;
            }
            if (t.charAt(i) != t.charAt(index)) {
                tUniform = false;
            }
        }

        // Printing the operations based on the uniformity of the parts of the strings
        if (!sUniform && !tUniform) {
            System.out.println("2");
            System.out.println("1 " + (index + 1) + " a");
            System.out.println("2 " + (index + 1) + " a");
        } else if (sUniform) {
            System.out.println("1");
            System.out.println("2 " + (index + 1) + " " + s.charAt(index));
        } else if (tUniform) {
            System.out.println("1");
            System.out.println("1 " + (index + 1) + " " + t.charAt(index));
        }
    }
}
