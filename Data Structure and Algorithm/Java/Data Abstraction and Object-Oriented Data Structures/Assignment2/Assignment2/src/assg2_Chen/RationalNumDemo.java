package assg2_Chen;
//Huan-Yun Chen
//CSCI 2540-001

public class RationalNumDemo {
	public static void main(String[] args) {
		RationalNum test = new RationalNum(2,3);
		RationalNum test1 = new RationalNum(3,4);
		RationalNum test3 = new RationalNum(2,3);
		RationalNum result;
		boolean resultBool;
		int test4 = 1;
		System.out.println(test.toString());
		System.out.println(test1.toString());
		result = test.add(test1);
		System.out.println(result.toString());
		result = test.sub(test1);
		System.out.println(result.toString());
		result = test.mul(test1);
		System.out.println(result.toString());
		result = test.div(test1);
		System.out.println(result.toString());
		result = test.neg();
		System.out.println(result.toString());
		result = test1.neg();
		System.out.println(result.toString());
		
		resultBool = test.equal(test1);
		System.out.println(resultBool);
		resultBool = test3.equal(test);
		System.out.println(resultBool);
		resultBool = test.equal(test4);
		System.out.println(resultBool);
		
		
	}

}