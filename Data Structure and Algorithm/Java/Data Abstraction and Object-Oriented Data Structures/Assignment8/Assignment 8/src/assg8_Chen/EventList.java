package assg8_Chen;

import java.util.LinkedList;
import java.util.ListIterator;
/**
 * @author Huan-Yun Chen
 * CSCI 2540-001
 */
public class EventList {
	private LinkedList list;
	/**
	 * evenlist constructor to create a new linked list
	 */
	public EventList()
	{
		list = new LinkedList();
	}
	/**
	 * 
	 * @return true/false determine is the list empty or not
	 */
	public boolean isEmpty()
	{
		return list.size()== 0;
	}
	/**
	 * 
	 * @param event the value to insert into the list
	 * insert use to plug in the value into the event list
	 */
	public void insert(int event)
	{
		list.add(event);
	}
	/**
	 * use iterator to print entire list
	 */
	public void printAll()
	{
		ListIterator a = list.listIterator();
		while(a.hasNext())
		{
			System.out.print(a.next()+" ");
		}
	}
	/**
	 * print the first value in the list
	 */
	public void printNext()
	{
		System.out.print(list.getFirst());
	}
	/**
	 * 
	 * @return the first integer in the list
	 * getnext use to get the first integer in the event list
	 */
	public int getNext()
	{
		Object a = list.getFirst();
		int answer = (Integer) a;
		return answer;
	}
	/**
	 * remove the first value from the event list 
	 */
	public void remove()
	{
		list.remove();
	}
}
