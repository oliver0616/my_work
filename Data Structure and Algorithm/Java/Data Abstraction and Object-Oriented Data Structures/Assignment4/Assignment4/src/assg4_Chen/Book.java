package assg4_Chen;
/**
 * 
 * @author Huan-Yun Chen
 * CSCI 2540-001
 * 
 * @declare bookId book's ID
 * @declare bookTitle book's title
 * @declare ISBN isbn code for the book
 * @declare authorLast author's last name
 * @declare category fiction or non fiction for the books
 * @declare flag use to keep track for the program to be able to determine to use
 * BookNotFindException class
 * 
 * this program allow the user to put a text file with a list of books that has
 * multiple information, by typing the id number to search up a specific information 
 */
public class Book 
{
	private int bookId;
	private String bookTitle;
	private String ISBN;
	private String authorLast;
	private char category;
	boolean flag = false;
	
// Constructor
/**
 * 
 * @param id bookId book's ID
 * @param title bookTitle book's title
 * @param isbnNum ISBN isbn code for the book
 * @param authorName authorLast author's last name
 * @param categoryL category fiction or non fiction for the books
 */
	public Book(int id, String title, String isbnNum, String authorName, char categoryL)
	{
		bookId = id;
		bookTitle = title;
		ISBN = isbnNum;
		authorLast = authorName;
		category = categoryL;
	}
	
//Method
/**
 * 
 * @return bookId return book's id
 */
	public int getBookId()
	{
		return bookId;
	}
/**
 * 
 * @return bookTitle return book title
 */
	public String getTitle()
	{
		return bookTitle;
	}
/**
 * 
 * @return ISBN return isbn
 */
	public String getISBN()
	{
		return ISBN;
	}
/**
 * 
 * @return authorLast return author last name
 */
	public String getAuthorLast()
	{
		return authorLast;
	}
/**
 * 
 * @return category return category of the book
 */
	public char getCategory()
	{
		return category;
	}
/**
 * 
 *return a string that has all the information about the book
 */
	public String toString()
	{
		int id; 
		String title;
		String isbnNum;
		String authorName;
		char categoryL;
		
		id =bookId;
		title = bookTitle;
		isbnNum = ISBN;
		authorName = authorLast;
		categoryL = category;
		
		return "Book id: "+ Integer.toString(id)+", Title: "+ title.toString()+
				", ISBN: "+isbnNum.toString()+", Author: "+ authorName.toString()+
				", "+ Character.toString(categoryL);
	}
/**
 * 
 * @param catagoryArray the array of the books
 * @param bookNum the total number of the books
 * @param numBookId the id user is searching for
 * 
 * this function allow the user to search for the book, when the user enter a
 * id that the program can't find, this function throw BookNotFindException class
 */
	public void bookSearch(Book catagoryArray[],int bookNum,int numBookId)
	{
		if(numBookId == 0)
		{
			System.out.println("Exit Program");
			System.exit(0);
		}
		for(int i = 1; i<= bookNum; i++)
		{
			if (numBookId == catagoryArray[i].bookId)
			{
				flag = true;
				System.out.println(catagoryArray[i].toString());
				break;
			}
			else
				flag = false;
		}
		if (flag == false)
		{
			new BookNotFindException();
		}
	}
}
