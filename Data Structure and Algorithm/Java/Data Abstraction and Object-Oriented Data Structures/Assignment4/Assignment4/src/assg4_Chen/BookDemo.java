package assg4_Chen;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
/**
 * 
 * @author Huan-Yun Chen
 * CSCI 2540-001
 *
 *test java.cpp this class use to test the book class and read the text file also 
 *put the input into an array
 */
public class BookDemo 
{
	public static void main(String args[]) throws FileNotFoundException 
	{
		File text = new File("catalog.txt");
		Scanner scan = new Scanner(text);
		Book booksArray []=new Book[100];
		int lineNumber=0;
		boolean on = true;
		
		Scanner scan1 = new Scanner(System.in);
		int idSearch;
		
		int id;
		String title;
		String isbnNum;
		String authorName;
		char categoryL;
		
		while(scan.hasNextLine())
		{
			String line = scan.nextLine();
			String[] splitStrings = line.split(" ");
			lineNumber++;
			id= Integer.parseInt(splitStrings[0]);
			title = splitStrings[1];
			isbnNum = splitStrings[2];
			authorName = splitStrings[3];
			categoryL = splitStrings[4].charAt(0);
			booksArray[lineNumber] = new Book(id,title,isbnNum,authorName,categoryL);
		}
		while(on)
		{
			System.out.print("Enter book id:");
			idSearch = scan1.nextInt();
			booksArray[lineNumber].bookSearch(booksArray,lineNumber,idSearch);
		}
	}
}
