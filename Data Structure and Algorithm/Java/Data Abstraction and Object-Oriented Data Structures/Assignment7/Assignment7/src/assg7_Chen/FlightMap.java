package assg7_Chen;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Scanner;

public class FlightMap implements FlightMapInterface 
{
	private ArrayList<LinkedList> map;

	/**
	 * Creates an empty FlightMap
	 */
	public FlightMap() 
	{
		map = new ArrayList<LinkedList>();
	}
	
	public void loadFlightMap(String cityFileName, String flightFileName)
			throws FileNotFoundException 
	{
		File cityF = new File(cityFileName);
		Scanner cityFScan = new Scanner(cityF);
		File flightF = new File(flightFileName);
		Scanner flightFScan = new Scanner(flightF);
		String a;
		String one;
		String two;
		
		while(cityFScan.hasNextLine())
		{
			LinkedList temp = new LinkedList();
			temp.add(new City(cityFScan.nextLine()));
			map.add(temp);
		}
		while(flightFScan.hasNextLine())
		{
			a = flightFScan.nextLine();
			String[] splitString = a.split("\t");
			one = splitString[0];
			two = splitString[1];
			insertAdjacent(new City(one),new City(two));
		}
	}

	public void insertAdjacent(City aCity, City adjCity) 
	{	
		ListIterator<LinkedList> iter = map.listIterator();
		boolean condiction = true;
		while(condiction)
		{
			if(iter.hasNext())
			{
				if(iter.next().getFirst().equals(aCity))
				{
					iter.previous().add(adjCity);
					condiction = false;
				}
				else
				{
					condiction = false;
				}
			}
		}
	}
	
	public void displayFlightMap() 
	{
		Iterator<LinkedList> alIterator = map.listIterator();
		while(alIterator.hasNext())
		{
			Iterator<City> llIterator = alIterator.next().iterator();
			System.out.print(llIterator.next().getName() + "\tDestinations: ");
			while(llIterator.hasNext())
			{
				System.out.print(llIterator.next().getName() + "; ");
			}
			System.out.print("\n");
		}
	}

	
	public void displayAllCities() 
	{
		System.out.println("These cities are served by the airline");
		Iterator<LinkedList> alIterator = map.listIterator();
		City tempCity = null;
		
		while(alIterator.hasNext())
		{
			tempCity = (City)alIterator.next().getFirst();
			System.out.println(tempCity.getName());
		}
	}

	public void displayAdjacentCities(City aCity) 
	{
		Iterator<City> llIterator = this.lookupLL(aCity).iterator();
		llIterator.next();
		while(llIterator.hasNext())
		{
			System.out.print(llIterator.next().getName() + "; ");
		}
	}
	
	public void markVisited(City aCity)
	{
		((City)this.lookupLL(aCity).getFirst()).visit();
	}
	
	public void unVisitAll() 
	{
		Iterator<LinkedList> alIterator = map.iterator();

		while(alIterator.hasNext())
		{
			((City)alIterator.next().getFirst()).clear();
		}
	}


	public boolean isVisited(City aCity) 
	{
		if(this.lookupLL(aCity) != null)
		{
			return ((City)this.lookupLL(aCity).getFirst()).isVisited();
		}
		return false;
	}

	
	public City getNextCity(City aCity) 
	{
		LinkedList tempLL = this.lookupLL(aCity);
		
		if(tempLL != null)
		{
			ListIterator<City> llIterator = tempLL.listIterator();
			llIterator.next();

			while(llIterator.hasNext())
			{
				if(!((City)this.lookupLL(llIterator.next()).getFirst()).isVisited())
				{
					return llIterator.previous();
				}
			}
		}
		return null;
	}

	
	public boolean servesCity(City aCity) 
	{
		if(this.lookupLL(aCity) != null /*&& this.lookupLL(aCity).size() > 1*/)
		{
			return true;
		}

		Iterator<LinkedList> alIterator = map.iterator();
		while(alIterator.hasNext())
		{
			Iterator<City> llIterator = alIterator.next().iterator();
			llIterator.next();
			while(llIterator.hasNext())
			{
				if(llIterator.next().equals(aCity))
				{
					return true;
				}
			}
		}
		return false;
	}


	public LinkedList<City> getPath(City originCity, City destinationCity) 
	{
		Stack<City> stacky = new Stack();
		City topCity, nextCity;
		
		this.unVisitAll(); // clear marks on all cities

		// push origin city onto a stack, mark it visited
		stacky.push(originCity);
		this.markVisited(originCity);

		topCity = stacky.peek();
		while(!stacky.isEmpty() &&
				!(topCity.equals(destinationCity)))
		{
			// loop invariant: stack contains a directed path
			// from the origin city at the bottom of the stack
			// to the city at the top of the stack

			// find an unvisited city adjacent to the city on
			// the top of the stack
			nextCity = this.getNextCity(topCity);

			if (nextCity == null)
			{
				stacky.pop(); // no city found; backtrack
			}
			else
			{
				stacky.push(nextCity);
				this.markVisited(nextCity);
			} // end if
			if(!stacky.isEmpty())
			{
				topCity = stacky.peek();
			}
		} // end while
		if (stacky.isEmpty())
		{
			// return that no path exists
			return null;
		}
		else
		{
			// return the path as a linked list
			LinkedList<City> thePath = new LinkedList<>();
			while(!stacky.isEmpty())
			{
				thePath.addFirst(stacky.pop());
			}
			return thePath;
		} // end if/else
	} // end getPath

	/**
	 * Determines if a given city is in the ArrayList and returns
	 * the LinkedList it is housed in.
	 * 
	 * @param aCity A city that is being searched for
	 * @return A LinkedList that is needed
	 */
	private LinkedList lookupLL(City aCity)
	{
		ListIterator<LinkedList> alIterator = map.listIterator();
		City tempCity = null;

		while(alIterator.hasNext())
		{
			tempCity = (City)alIterator.next().getFirst();
			if(tempCity.equals(aCity))
			{
				return alIterator.previous();
			}
		}
		return null;
	}
}
