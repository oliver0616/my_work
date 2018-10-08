package assg9_Chen;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * 
 * @author Huan-Yun Chen
 * CSCI 2540-001
 *
 */
public class menu implements userInterface{

	Scanner scan = new Scanner(System.in);
	phoneBook a ;
	
/**
 * @constructor menu() to create a phoneBook object
 */
	public menu()
	{
		a =new phoneBook();
	}
//================================================================================	
	/**
	 * 
	 * @throws FileNotFoundException
	 * @method to read the text file and create the binary tree
	 */
	public void loadData() throws FileNotFoundException
	{
		File text = new File("phoneBook.txt");
		Scanner scan = new Scanner(text);
		String input;
		while(scan.hasNextLine())
		{
			input = scan.nextLine();
			String[] splitString = input.split("\\s+");
			String firstName = splitString[0];
			String lastName = splitString[1];
			String phoneNum = splitString[2];
			String fullName = firstName +" "+ lastName;
			person a1 = new person(fullName,phoneNum);
			a.addNode(a1);
		}
	}
	/**
	 * 
	 * @method printOutBook to print out the tree
	 */
	public void printOutBook()
	{
		a.inOrderTraverseTree(a.root);
	}
//==================================================================================
	/**
	 * 
	 * @method add allow user to add the new name with phone number
	 */
	public void add()
	{
		String newName;
		String newPhoneNum;
		System.out.println("Please Enter a Name: ");
		newName = scan.nextLine();
		System.out.println("Please Enter a Phone Number: ");
		newPhoneNum = scan.nextLine();
		person brandNew = new person(newName, newPhoneNum);
		a.addNode(brandNew);
	}
	/**
	 * 
	 * @method delete allow user to delete information by searching the name
	 */
	public void delete()
	{
		String deleteName;
		System.out.println("Please Enter a Name: ");
		deleteName = scan.nextLine();
		a.remove(deleteName);
		System.out.println("User has been remove");	
	}
	/**
	 * 
	 * @method find allow user to find the user name by entering the phone number
	 */
	public void find()
	{
		String phoneNumberFind;
		node newUser;
		System.out.println("Please Enter a Phone Number to find the user: ");
		phoneNumberFind = scan.next();
		newUser = a.searchPhoneNum(a.root, phoneNumberFind);
		a.storeNumSwitch = true;
		if(a.userENumber == false)
		{
			System.out.println("User not exsit");
		}
		a.userENumber = false;
	}
	/**
	 * 
	 * @method change allow user to change the phone number that already exist
	 * by giving the name
	 */
	public void change()
	{
		String nameFound;
		
		System.out.println("Please Enter a Name to change its number: ");
		nameFound = scan.nextLine();
		a.searchName(a.root, nameFound);
		a.storeNameSwitch = true;
		if(a.userEName == false)
		{
			System.out.println("User not exist");
		}
		a.userEName = false;
	}
	/**
	 *
	 * @method quit allow user to quit the program also save the data into the
	 * same text file
	 */
	public void quit() throws FileNotFoundException
	{
		a.save(a.root);
		a.writer.close();
	}
}
