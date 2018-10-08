package assg9_Chen;

import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * 
 * @author Huan-Yun Chen
 * CSCI 2540-001
 * 
 * mainFunction all it does its running the menu and call the value class 
 * for functions
 */
public class mainFuntion {
	public static void main(String[] args) throws FileNotFoundException  
	{
		menu user = new menu();
		Scanner scan = new Scanner(System.in);
		int choice;
		user.loadData();
		while(true)
		{
			System.out.println("");
			System.out.println("1.Add Name and Phone number");
			System.out.println("2.Delete Name and Phone number");
			System.out.println("3.Find the User by Phone Number");
			System.out.println("4.Change the Phone number");
			System.out.println("5.Quit and save the data");
			System.out.println("6.Print the Phone Book Data");
			System.out.println("Enter a number to select your action:");
			choice = scan.nextInt();
			if(choice ==1)
			{
				user.add();
			}
			else if(choice ==2)
			{
				user.delete();
			}
			else if(choice ==3)
			{
				user.find();
			}
			else if(choice ==4)
			{
				user.change();
			}
			else if(choice ==5)
			{
				user.quit();
				System.exit(0);
			}
			else if(choice ==6)
			{
				user.printOutBook();
			}
		}
	}
}
