package assg8_Chen;
/**
 * @author Huan-Yun Chen
 * CSCI 2540-001
 */
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Simulate {
/**
 * 
 * @throws FileNotFoundException for file exception
 * the main function contain loading the text file into two different kind of list
 * one is arrive and other is depart. the main function also print out the event 
 * simulate the entire process and calculate out the total number of people, avaerage
 * amount of time spent waiting
 */
	public static void main(String[] args) throws FileNotFoundException 
	{
		int costumerNum = 1;
		double averageTime= 0;
		int tempTime= 0;
		
		int arriveTime;
		int processTime;		
		int departTime;
		int departMaxTime;
		EventList arriveList = new EventList();
		EventList departList = new EventList();
		File file = new File("input.txt");
		Scanner scan = new Scanner(file);
		String input;
//===================================================================================
		//Load Data into the EventList
		input = scan.nextLine();
		String[] splitString = input.split("\t");
		String arriveString = splitString[0];
		String timeString = splitString[1];
		arriveTime = Integer.parseInt(arriveString);
		processTime = Integer.parseInt(timeString);
		departTime = arriveTime + processTime;
		departMaxTime = departTime;
		arriveList.insert(arriveTime);
		departList.insert(departTime);
		
		
		while(scan.hasNextLine())
		{
				input = scan.nextLine();
				splitString = input.split("\t");
				arriveString = splitString[0];
				timeString = splitString[1];
				arriveTime = Integer.parseInt(arriveString);
				processTime = Integer.parseInt(timeString);
				
				if(arriveTime<departTime)
				{
					departTime = processTime + departMaxTime;
					tempTime = departMaxTime-arriveTime ;
					if(tempTime > 0)
					{
						averageTime = averageTime +tempTime;
					}
					departMaxTime = departTime;
					arriveList.insert(arriveTime);
					departList.insert(departTime);
				}
				else if(arriveTime>departTime)
				{
					departMaxTime = arriveTime;
					departTime = processTime +departMaxTime;
					tempTime = departMaxTime-arriveTime ;
					if(tempTime > 0)
					{
						averageTime = averageTime +tempTime;
					}
					arriveList.insert(arriveTime);
					departList.insert(departTime);
					departMaxTime = departTime;
				}
				costumerNum++;
		}
		averageTime = averageTime / costumerNum;
//==================================================================================
		//Print Events
		System.out.println("Simulation Begins");
		while(!arriveList.isEmpty()&&!departList.isEmpty())
		{
			if(arriveList.getNext() < departList.getNext())
			{
				System.out.println("Processing an arrival event at time: "
						+arriveList.getNext());
				arriveList.remove();
			}
			else if(departList.getNext() < arriveList.getNext())
			{
				System.out.println("Processing an departure event at time: "
						+departList.getNext());
				departList.remove();
			}
			else if(arriveList.getNext()==departList.getNext())
			{
				System.out.println("Processing an arrival event at time: "
						+arriveList.getNext());
				arriveList.remove();
				System.out.println("Processing an departure event at time: "
						+departList.getNext());
				departList.remove();
			}
		}
		
		while(!arriveList.isEmpty())
		{
			System.out.println("Processing an arrive event at time:"
					+arriveList.getNext());
			arriveList.remove();
		}
		
		while(!departList.isEmpty())
		{
			System.out.println("Processing an depart event at time:"
					+departList.getNext());
			departList.remove();
		}
		System.out.println("Simulation End");
		System.out.println("");
		System.out.println("Final Statistics:");
		System.out.println("Total number of people processed:"+costumerNum);
		System.out.println("Average amount of time spent waiting:"+averageTime);
		
	}
}
