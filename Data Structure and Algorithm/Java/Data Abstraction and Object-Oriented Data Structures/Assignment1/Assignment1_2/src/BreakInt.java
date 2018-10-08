//Name: Huan-Yun Chen
//CSCI 2540-001

import java.util.Scanner;

public class BreakInt {
	
	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in); // scan keyboard
		int number; //user input
		
		System.out.println("Please enter an integer:");
		number = scan.nextInt();
		
		// in this while loop get the remainder first and print it out
		// then /10 to get rid off the number and loop until the number = 0
		while (number > 0) {
			System.out.println( number % 10);
		    number = number / 10;
		}
		scan.close();
	}
}
