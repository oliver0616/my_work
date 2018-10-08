//Name: Huan-Yun Chen
//CSCI 2540-001

import java.util.Scanner;

public class grades {
	
	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in);
		Scanner scan1 = new Scanner(System.in);
		int numOfGrades;  // number of grades
		int grades = 0;  // store the input from user(the grades)
		int c = 0;  // store the value go through the array
		int total =0 ;  // store the total grades
		int average;  // store the average grades
		int counter = 0; // count the grades that are higher than average
		
		System.out.print("Please enter the number of grades:");
		numOfGrades = scan.nextInt(); 
		//
		if (numOfGrades<=0){
			System.out.print("ERROR NUMBER LESS THAN 0");
			System.exit(0);
		}
			int[] gradeArray = new int[numOfGrades];	
		// Put each number into array
		for(int a = 0; a<numOfGrades; a++){
			System.out.print("Enter a grade:");			
			grades = scan1.nextInt();
			gradeArray[a] = grades;
			total = total + grades;
		}
		average = total / numOfGrades ;
		System.out.println("The average grade is:"+ average);
		System.out.println("The grades above the average grade are:");
		
		// find the grades that are bigger than the average
		for(int a =0; a<numOfGrades; a++){
		   c = gradeArray[a];
		   if(c > average){
			   System.out.println(c);
			   counter ++;
		   }
		}
		System.out.println("for a total of "+ counter+" grades");
		scan.close();
		scan1.close();
	}
}
