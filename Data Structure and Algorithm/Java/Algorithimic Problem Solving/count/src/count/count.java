package count;

import java.util.Scanner;

public class count {
	public static void main(String[] args) {
	
	String book;
	int book_len;
	Scanner scan;
	char cm;
	int cm_code;
	int aC=0;int bC=0;int cC=0;int dC=0;int eC=0;int fC=0;int gC=0;int hC=0;int iC=0;
	int jC=0;int kC=0;int lC=0;int mC=0;int nC=0;int oC=0;int pC=0;int qC=0;int rC=0;
	int sC=0;int tC=0;int uC=0;int vC=0;int wC=0;int xC=0;int yC=0;int zC=0;
	int space=0;
	int enter =0;
	
	
	
	
	scan = new Scanner(System.in);
	System.out.println("Put in the message");
	book = scan.nextLine();
	book_len = book.length();
	
	for (int i=0;i<book_len;i++)	
		{
		cm= book.charAt(i);
		cm_code= cm;
		if (cm_code == 97||cm_code == 65)
			aC++;
		if (cm_code == 98||cm_code == 66)
			bC++;
		if (cm_code == 99||cm_code == 67)
			cC++;
		if (cm_code == 100||cm_code == 68)
			dC++;
		if (cm_code == 101||cm_code == 69)
			eC++;
		if (cm_code == 102||cm_code == 70)
			fC++;
		if (cm_code == 103||cm_code == 71)
			gC++;
		if (cm_code == 104||cm_code == 72)
			hC++;
		if (cm_code == 105||cm_code == 73)
			iC++;
		if (cm_code == 106||cm_code == 74)
			jC++;
		if (cm_code == 107||cm_code == 75)
			kC++;
		if (cm_code == 108||cm_code == 76)
			lC++;
		if (cm_code == 109||cm_code == 77)
			mC++;
		if (cm_code == 110||cm_code == 78)
			nC++;
		if (cm_code == 111||cm_code == 79)
			oC++;
		if (cm_code == 112||cm_code == 80)
			pC++;
		if (cm_code == 113||cm_code == 81)
			qC++;
		if (cm_code == 114||cm_code == 82)
			rC++;
		if (cm_code == 115||cm_code == 83)
			sC++;
		if (cm_code == 116||cm_code == 84)
			tC++;
		if (cm_code == 117||cm_code == 85)
			uC++;
		if (cm_code == 118||cm_code == 86)
			vC++;
		if (cm_code == 119||cm_code == 87)
			wC++;
		if (cm_code == 120||cm_code == 88)
			xC++;
		if (cm_code == 120||cm_code == 89)
			yC++;
		if (cm_code == 120||cm_code == 90)
			zC++;
		if(cm_code==32)
			space++;
		if(cm_code==13)
			enter++;
		}
		System.out.println("In this message");
		System.out.println("a has:"+aC);
		System.out.println("b has:"+bC);
		System.out.println("c has:"+cC);
		System.out.println("d has:"+dC);
		System.out.println("e has:"+eC);
		System.out.println("f has:"+fC);
		System.out.println("g has:"+gC);
		System.out.println("h has:"+hC);
		System.out.println("i has:"+iC);
		System.out.println("j has:"+jC);
		System.out.println("k has:"+kC);
		System.out.println("l has:"+lC);
		System.out.println("m has:"+mC);
		System.out.println("n has:"+nC);
		System.out.println("o has:"+oC);
		System.out.println("p has:"+pC);
		System.out.println("q has:"+qC);
		System.out.println("r has:"+rC);
		System.out.println("s has:"+sC);
		System.out.println("t has:"+tC);
		System.out.println("u has:"+uC);
		System.out.println("v has:"+vC);
		System.out.println("w has:"+wC);
		System.out.println("x has:"+xC);
		System.out.println("y has:"+yC);
		System.out.println("z has:"+zC);
		System.out.println("Space has:"+space);
		System.out.println("Enter has:"+enter);
	}
}
