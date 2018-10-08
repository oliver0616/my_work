package assg9_Chen;
import java.io.FileNotFoundException;

/**
 * 
 * @author Huan-Yun Chen
 * CSCI 2540-001
 *
 * userInterface is a interface for menu to use
 * @method add() allow user to add the new name and new phone number
 * @method delete() allow user to delete the data in the tree and input file
 * @method find() allow user to search for data in the tree
 * @method change() allow user to change the phone number
 * @method quit() alow user to quit the program and save the data back into 
 * text file
 */
public interface userInterface {
	public void add();
	public void delete();
	public void find();
	public void change ();
	public void quit()throws FileNotFoundException ;
}
