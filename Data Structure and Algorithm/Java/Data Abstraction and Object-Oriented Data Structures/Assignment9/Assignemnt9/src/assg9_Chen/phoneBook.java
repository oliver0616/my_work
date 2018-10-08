package assg9_Chen;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.io.PrintWriter;
/**
 * 
 * @author Huan-Yun Chen
 * CSCI 2540-001
 *
 * phoneBook class contain the binary tree methods
 */
public class phoneBook {
/**
 * @declare root the root of the tree which is the node at the very top
 * @declare storeNameSwitch a switch to store the value for the person that
 * user is searching for
 * @declare userEName a boolean to record searchName method find a user or not
 * @declare storeNumSwitch a switch to store the value for the phone number that
 * user is searching for
 * @declare userENumber a boolean to record searchPhoneNum method find a number
 * or not
 * @declare compareName used to store the name user is looking for
 * @declare compareNUm used to store the number user is looking for
 * @declare writer used to write the out put file
 * @declare writerSwitch a switch allow the program to new a print writer and not
 * creating too many of them
 */
	node root;
	boolean storeNameSwitch = true;
	boolean userEName = false;
	boolean storeNumSwitch = true;
	boolean userENumber = false;
	String compareName ="";
	String compareNum ="";
	PrintWriter writer;
	boolean writerSwitch = true;
	
	/**
	 * 
	 * @param i the person data that going to add as a node
	 * @method addNode create node, the new data in the tree.
	 */
	public void addNode(person i)
	{
		node newNode = new node(i);
		
		if(root == null)
		{
			root = newNode;
		}
		else
		{
			node focusNode = root;
			node parent;
			while(true)
			{
				parent = focusNode;
				if(i.name.compareTo(focusNode.item.name) <0 )
				{
					focusNode = focusNode.leftChild;
					if(focusNode == null)
					{
						parent.leftChild=newNode;
						return;	
					}
				}
				else
				{
					focusNode = focusNode.rightChild;
					if(focusNode == null)
					{
						parent.rightChild=newNode;
						return;
					}
				}
			}
		}
	}
/**
 * 
 * @param focusNode the node to start with usually it's the root
 * @method inOrderTraverseTree print out the tree in a in order
 */
	public void inOrderTraverseTree(node focusNode)
	{
		if(focusNode != null)
		{
			inOrderTraverseTree(focusNode.leftChild);
			System.out.println(focusNode);
			inOrderTraverseTree(focusNode.rightChild);		
		}
	}
/**
 * 
 * @param n the string that user want to remove
 * @return return true if node get remove fine, return false if can't find the node
 * @method remove this method remove a specific node in the tree, by using the 
 * String n search through the tree
 */
	public boolean remove(String n)
	{
		node focusNode = root;
		node parent = root;
		
		boolean isItLeftChild = true;
		while(!focusNode.item.name.equalsIgnoreCase(n))
		{	
			parent = focusNode;
			//left child
			if(n.compareTo(focusNode.item.name)< 0)
			{
				isItLeftChild = true;
				
				focusNode = focusNode.leftChild;
			}
			//right child
			else
			{
				isItLeftChild = false;
				
				focusNode = focusNode.rightChild;
			}
			//empty
			if(focusNode == null)
			{
				System.out.println("User not exist");
				return false;
			}	
		}	
		// when no children under parent
		if(focusNode.leftChild == null&& focusNode.rightChild == null)
		{
			// root
			if(focusNode == root)
			{
				root = null;
			}
			//left child
			else if(isItLeftChild)
			{
				parent.leftChild = null;
			}
			//right child
			else
			{
				parent.rightChild = null;
			}
		}
		//when there is no right child
		else if (focusNode.rightChild == null)
		{
			//root
			if(focusNode == root)
			{
				root = focusNode.leftChild;
			}
			// left child
			else if(isItLeftChild)
			{
				parent.leftChild = focusNode.leftChild;
			}
			//right child
			else
			{
				parent.rightChild = focusNode.leftChild;
			}
		}
		//when there is no left child
		else if(focusNode.leftChild == null)
		{
			//root
			if(focusNode == root)
			{
				root = focusNode.rightChild;
			}
			//left child
			else if(isItLeftChild)
			{
				parent.leftChild = focusNode.rightChild;
			}
			//right child
			else
			{
				parent.rightChild =focusNode.leftChild;
			}
		}
		// parent connect to two children
		else
		{
			node replacement = getReplacementNode(focusNode);
			//root
			if(focusNode == root)
			{
				root = replacement;
			}
			//left child
			else if(isItLeftChild)
			{
				parent.leftChild = replacement;
			}
			//right child
			else
			{
				parent.rightChild = replacement;
			}
			replacement.leftChild = focusNode.leftChild;
		}
		return true;
	}
/**
 * 
 * @param replaceNode the node need to be replace
 * @return return replace node
 * this method deal with the action when the parent has 2 children and the parent
 * need to be remove. it does the action of connecting
 */
	public node getReplacementNode(node replaceNode)
	{
		node replacementParent = replaceNode;
		node replacement =replaceNode;
		
		node focusNode = replaceNode.rightChild;
		
		while(focusNode != null)
		{
			replacementParent = replacement;
			
			replacement = focusNode;
			
			focusNode = focusNode.leftChild;
		}
		
		if(replacement != replaceNode.rightChild)
		{
			replacementParent.leftChild = replacement.rightChild;
			replacement.rightChild = replaceNode.rightChild;
		}
		return replacement;
	}
/**
 * 
 * @param focusNode the root node to start with
 * @param phoneNumber the phone number user trying to look for
 * @return the node return for recursion
 * @method searchPhoneNum search the phone number and print out the message saying
 * the number belong to witch person
 */
	public node searchPhoneNum(node focusNode,String phoneNumber)
	{
		if(storeNumSwitch)
		{
			compareNum = phoneNumber;
			storeNumSwitch = false;
		}
		if(focusNode != null)
		{
			searchPhoneNum(focusNode.leftChild, phoneNumber);
			if(phoneNumber.equals(focusNode.item.phoneNum))
			{
				System.out.println("This number belong to:"+ focusNode.item.name);
				userENumber = true;
				return null;
			}
			searchPhoneNum(focusNode.rightChild, phoneNumber);
			if(phoneNumber.equals(focusNode.item.phoneNum))
			{
				System.out.println("This number belong to:"+ focusNode.item.name);
				userENumber = true;
				return null;
			}
		}
		return focusNode;
		
	}
/**
 * 
 * @param focusNode the node to start with
 * @param newName the name that user trying to look for
 * @return the node return for the recursion
 * @method searchName search the name in the tree and ask user to enter new phone
 * number to replace the old one
 */
	public node searchName (node focusNode,String newName)
	{
		if (storeNameSwitch)
		{
			compareName = newName;
			storeNameSwitch = false;
		}
		if(focusNode!= null)
		{
			searchName(focusNode.leftChild, newName);
			if(compareName.equals(focusNode.item.name))
			{
				String newPhoneNumber;
				Scanner scan = new Scanner(System.in);
				System.out.println("Please Enter a new number to replace old Number:"
						);
				newPhoneNumber = scan.next();
				focusNode.item.phoneNum = newPhoneNumber;
				System.out.println("Number has been change");
				userEName = true;
				return null;
			}
			searchName(focusNode.rightChild, newName);
			if(compareName.equals(focusNode.item.name))
			{
				String newPhoneNumber;
				Scanner scan = new Scanner(System.in);
				System.out.println("Please Enter a new number to replace old Number:"
						);
				newPhoneNumber = scan.next();
				focusNode.item.phoneNum = newPhoneNumber;
				System.out.println("Number has been change");
				userEName = true;
				return null;
			}
		}
		return focusNode;
	}
/**
 * 
 * @param focusNode the node to start with
 * @throws FileNotFoundException used to handle the file not found exception
 * @method save write the data back to the input file and replace the old data
 */
	public void save(node focusNode) throws FileNotFoundException
	{	
		if(writerSwitch)
		{
			writer = new PrintWriter("phoneBook.txt");
			writerSwitch = false;
		}
		if(focusNode != null)
		{
			save(focusNode.leftChild);
			if(focusNode != null)
			{
				System.out.println(focusNode);
				writer.println(focusNode.toString());
			}		
			save(focusNode.rightChild);	
		}
	}
	
}
