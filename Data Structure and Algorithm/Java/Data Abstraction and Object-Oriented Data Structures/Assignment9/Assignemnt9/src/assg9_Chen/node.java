package assg9_Chen;

/**
 * 
 * @author Huan-Yun Chen
 * CSCI 2540-001
 *
 *	this is the node class to create the tree, it contains data for a tree
 */
public class node {
/**
 * @declare item the item that store the person class
 * @declare leftChild like a pointer point toward the left child
 * @declare rightChild like a pointer point toward the right child
 */
	person item;
	node leftChild;
	node rightChild;
/**
 * 
 * @param i the person value store into each node
 * @constructor node(i) constructor to create a node
 */
	public node(person i)
	{
		item = i;
	}
/**
 * 
 * @method toString to return the node as a string object
 */
	public String toString()
	{
		return item.name +"\t"+item.phoneNum;
	}
	
}
