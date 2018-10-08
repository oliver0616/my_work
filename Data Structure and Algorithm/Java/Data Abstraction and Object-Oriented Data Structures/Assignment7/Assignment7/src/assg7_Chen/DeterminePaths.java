package assg7_Chen;
import java.io.FileNotFoundException;
import java.io.File;
import java.util.LinkedList;
import java.util.Scanner;

public class DeterminePaths 
{
	public static void main(String[] args) throws FileNotFoundException
	{
		FlightMap test = new FlightMap();
		test.loadFlightMap("cityFile.txt", "flightFile.txt");
		
		File requestFile = new File("requestFile.txt");
		Scanner requestFScan = new Scanner(requestFile);
		String requestScan;
		String requestScan1 = null;
		String requestScan2= null;
		City a;
		City b;
		while(requestFScan.hasNextLine())
		{
			requestScan = requestFScan.nextLine();
			String[] splitStrings = requestScan.split("\t");
			requestScan1 = splitStrings[0];
			requestScan2 = splitStrings[1];
			//System.out.println("Flight from:"+requestScan1+" to "+requestScan2);
			a = new City(requestScan1);
			b = new City(requestScan2);
			if(test.servesCity(a)== false)
			{
				System.out.println("The original airline does not serve city"+ requestScan1);
				System.out.println(requestScan2);
			}
			else if (test.servesCity(b)==false)
			{
				System.out.println("The destination airline does not serve city"+ requestScan2);
			}
			else if (test.servesCity(a)== true && test.servesCity(b)==true)
			{	
				
					System.out.println("The following sequence of flights exist between "
							+requestScan1+" to "+requestScan2);
					System.out.println(test.getPath(a, b));					
			}
		}		
	}
}
