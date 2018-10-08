package assg3_Chen;
/**
 * 
 * @author Huan-Yun Chen
 * CSCI 2540-001
 * 
 * @declare acctNo number of the account
 * @declare balance the money left in the account
 * @declare counter the counter for the acctNo
 * 
 * creating a student account that has different functions like bank account 
 */
public class StudentAccount 
{
	private long acctNo ;
	private double balance;
	static int counter=0;
	
// Constructors	
	/**
	 * 
	 * @declare acctNo number of the account
	 * @declare balance the money left in the account 
	 */
	public StudentAccount()
	{
	acctNo = counter++;
	balance = 0;
	}
	/**
	 * 
	 * @param initialBalance the value that store into the current balance
	 */
	public StudentAccount(double initialBalance)
	{
		acctNo = counter++;
		balance = initialBalance;
	}
// Methods
	/**
	 * 
	 * @return return account number
	 */
	public long getAcctNo()
	{
		return acctNo;
	}
	/**
	 * 
	 * @return  return the balance
	 */
	public double getBalance()
	{
		return balance;
	}
	/**
	 * 
	 * @return return the counter value
	 */
	public int getCounter()
	{
		return counter;
	}
	/**
	 * 
	 * @param theBalance the value user going to set
	 * set a balance for the account
	 */
	public void setBalance(double theBalance)
	{
		if (theBalance < 0)
		{
			System.out.println("Negative new balance!");
		}
		else
			balance = theBalance;
	}
	/**
	 * 
	 * @param monDeposit the money user going to put in account
	 * store the value into the student account balance
	 */
	public void deposit(double monDeposit)
	{
		if(monDeposit < 0)
		{
			System.out.println("Negative number enter!");
		}
		else	
			balance = balance +monDeposit;
	}
	/**
	 * 
	 * @param monCharge the money user going to take out from account
	 * take out the value from the student account balance
	 */
	public void charge(double monCharge)
	{
		if(monCharge < 0)
		{
			System.out.println("Negative number enter!");
		}
		else
			balance = balance - monCharge;
	}
	/**
	 * 
	 * @param randomStudent the account that want to take the money from
	 * @param amount the value that going to take out from the balance
	 * take the amount of value from balance out of the randomStudent and give it to
	 * other account 
	 */
	public void transferIn(StudentAccount randomStudent, double amount)
	{
		if(amount < 0)
		{
			System.out.println("Negative number enter!");
		}
		else
		{
			randomStudent.balance=randomStudent.getBalance()-amount;
			balance = balance + amount;
		}
	}
	/**
	 * 
	 * @param randomStudent the account that want to take the money from
	 * @param amount amount the value that going to take out from the balance
	 * give the amount of value from the balance out of the student and give it to
	 * the randomStudent
	 */
	public void transferOut(StudentAccount randomStudent, double amount)
	{
		if(amount <0)
		{
			System.out.println("Negative number enter!");
		}
		else
		{
			randomStudent.balance=randomStudent.getBalance()+amount;
			balance = balance -amount;
		}
	}
	/**
	 * print the Info of the current state
	 */
	public void printInfo()
	{
		System.out.println("Account Number: "+acctNo);
		System.out.println("Current balance: "+balance);
	}
	/**
	 * @return return the string of the information
	 * turn account number and current balance into the string
	 */
	public String toString()
	{
		Long accountNum;
		Double balanceLeft;
		accountNum=acctNo;
		balanceLeft=balance;
		return "Account Number:"+accountNum.toString()+"\nCurrent Balance: "+ balanceLeft.toString();
	}
}





	
	

