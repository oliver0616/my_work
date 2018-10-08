package assg7_Chen;

public class Stack<E> implements StackInterface<E> {
	private Node<E> first; // top of the stack
	private int size;	// size of the stack

	/**
	 * Creates an empty stack
	 */
	public Stack() 
	{
		first = null;
		size = 0;
	}
	
	
	public boolean isEmpty() 
	{
		if(first == null)
		{
			return true;
		}
		else
		{
			return false;	
		}		
	}

	public void popAll() 
	{	
		for(int i = 0; i < size;i++)
		{
			System.out.println(pop());
		}
		System.out.println("Stack is empty");
	}

	public void push(E newItem) throws StackException 
	{
			Node<E> oldNode = first;
			first = new Node<E>(newItem,oldNode);
			size++;
	}

	public E pop() throws StackException 
	{
			E item = first.getItem();
			first = first.getNext();
			size--;
			return item;
	}

	
	public E peek() throws StackException 
	{
		return first.getItem();
	}

	public void print()
	{
		first.getItem().toString();
	}
}
