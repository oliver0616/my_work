package assg3_Chen;

public class StudentAccountDemo {
	public static void main(String[] args) 
	{
//StudentAccount test
		System.out.println("StudentAccount test");
		StudentAccount oliver = new StudentAccount(1000);
		//oliver 1000
		StudentAccount kyle = new StudentAccount(1500);
		//kyle 1500
		System.out.println(oliver.toString()+"\n");
		System.out.println(kyle.toString()+"\n");
		System.out.println("SetBalance $2000");
		oliver.setBalance(2000);
		//oliver 2000
		System.out.println(oliver.toString()+"\n");
		System.out.println("Deposit $500");
		oliver.deposit(500);
		//oliver 2500
		System.out.println(oliver.toString()+"\n");
		System.out.println("Charge $1000");
		oliver.charge(1000);
		//oliver 1500
		System.out.println(oliver.toString()+"\n");
		System.out.println("TransferOut Oliver to Kyle 500");
		oliver.transferOut(kyle, 500);
		//oliver 1000
		//kyle 2000
		System.out.println(oliver.toString()+"\n");
		System.out.println(kyle.toString()+"\n");
		System.out.println("TransferIn Kyle to Oliver $1000");
		oliver.transferIn(kyle, 1000);
		//oliver 2000
		//kyle 1000
		System.out.println(oliver.toString()+"\n");
		System.out.println(kyle.toString()+"\n");
		//oliver 2000
		System.out.println("PrintInfo");
		oliver.printInfo();
		System.out.println("");
//RewardsAccount test
		System.out.println("RewardsAccount test");
		RewardsAccount paul = new RewardsAccount(3000);
		//paul 3000 rewards:5
		System.out.println(paul.toString()+"\n");
		System.out.println("Deposit $100");
		paul.deposit(100);
		//paul 3100 rewards:10
		System.out.println(paul.toString()+"\n");
		System.out.println("Deposit $100");
		paul.deposit(100);
		//paul 3200 rewards:15
		System.out.println(paul.toString()+"\n");
		System.out.println("Deposit $100");
		paul.deposit(100);
		//paul 3300 rewards:20
		System.out.println(paul.toString()+"\n");
		System.out.println("Deposit $100");
		paul.deposit(100);
		//paul 3400 rewards:25
		System.out.println(paul.toString()+"\n");
		System.out.println("redeemRewards");
		paul.redeemRewards();
		//paul 3425 rewards:0
		System.out.println(paul.toString()+"\n");
		paul.printInfo();
		
	}
}