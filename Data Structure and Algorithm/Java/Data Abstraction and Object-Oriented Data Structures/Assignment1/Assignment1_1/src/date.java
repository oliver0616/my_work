//Name: Huan-Yun Chen
//CSCI 2540-001

import java.util.Scanner;

public class date {
	
	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in); // scan keyboard
	    String Date, day, month, year; //user input
	    
	    System.out.println("Enter a date in the form month/day/year:");
	    Date = scan.nextLine();

	    String[] splitStrings = Date.split("/"); // split the strings by / in to 3 parts
	    month=splitStrings[0]; // store the month's value into month
	    day=splitStrings[1];   // store the day's value into day
	    year=splitStrings[2];  // store the year's value into year

	    System.out.println("Your date in European form is:\n " + day + "." + month + "."+ year );
	    scan.close();
	}
}
