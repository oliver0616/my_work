import java.util.Scanner;
public class change {
	
	public static void main(String[] args) {
	
		double money;
		int hundred;
		int fifty;
		int twenty;
		int ten;
		int five;
		int two;
		int one;
		int quarter;
		int dimes;
		int nickles;
		int pennies;
		
		
		Scanner scan;
		scan = new Scanner(System.in);
		 
		System.out.println("Hello,User");
		System.out.println("Type in the money that you wnat to convert to change:");
		money = scan.nextDouble();
		
		hundred =(int)(money/100);
		money %= 100;
		fifty = (int)(money/50);
		money %= 50;
		twenty =(int)(money/20);
		money %= 20;
		ten =(int)(money/10);
		money %= 10;
		five = (int)(money/5);
		money%= 5;
		two = (int)(money/2);
		money %= 2;
		one = (int)(money/1);
		money %=1;
		quarter = (int)(money/0.25);
		money %= 0.25;
		dimes = (int)(money/0.10);
		money %= 0.10;
		nickles = (int)(money/0.05);
		money %= 0.05;
		pennies = (int)(money/0.01);
		money %= 0.01;
		
		System.out.println("Hundred = "+ hundred);
		System.out.println("Fifty = "+ fifty);
		System.out.println("Twenty = "+ twenty);
		System.out.println("Ten = "+ ten);
		System.out.println("Five = "+ five);
		System.out.println("Two = "+ two);
		System.out.println("One = "+ one);
		System.out.println("Quarters = "+ quarter);
		System.out.println("Dimes = "+ dimes);
		System.out.println("Nickles = "+ nickles);
		System.out.println("Pennies = "+ pennies);
	}
}
