package assg3_Chen;
/**
 * 
 * @author Huan-Yun Chen
 * CSCI 2540-001
 * 
 * @declare rewards the amount of value get from rewards
 * 
 * create a rewards account that not just have the student account feature also have
 * reward system 
 */
public class RewardsAccount extends StudentAccount {
	double rewards;
		
	// Constructors
	/**
	 * when rewards value are 0 
	 */
	public RewardsAccount()
	{
		rewards = 0;
	}
	/**
	 * 
	 * @param initialBalance the value that store into the current balance and add $5
	 * rewards
	 */
	public RewardsAccount(double initialBalance)
	{
		super(initialBalance);
		if(initialBalance >= 100)
		{
			rewards = rewards + 5;
		}
	}
	//Methods
	/**
	 * 
	 * @return rewards return rewards value
	 */
	public double getRewards()
	{
		return rewards;
	}
	/**
	 * put the rewards value into current balance and change rewards into 0	
	 */
	public void redeemRewards()
	{
		if(rewards >= 25)
		{
			super.deposit(rewards);
			rewards = 0;
		}
		else if(rewards < 25)
		{
			System.out.println("Rewards less than 25, need more rewards");
		}
	}
	/**
	 * @return return the string of Student account information and rewards balance	
	 */
	public String toString()
	{
		Double balanceReward;

		balanceReward=rewards;
		return super.toString()+"\nRewards Balance: "+balanceReward.toString();
	}
	/**
	 * 
	 * @param amount the value user want to store into the account
	 * store the value of the user input into the current balance and add $5 rewards
	 */
	public void deposit(double amount)
	{
		if(amount >= 100)
		{
			rewards = rewards +5;
			super.deposit(amount);
		}
	}
	/**
	 * print out the information which included reward balanc, current balance and
	 * account number
	 */
	public void printInfo()
	{
		super.printInfo();
		System.out.print("Rewards Balance:" + rewards);
	}
}
