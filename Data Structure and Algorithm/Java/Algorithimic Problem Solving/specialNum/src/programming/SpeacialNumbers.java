package programming;

public class SpeacialNumbers {
	
	    private static long result;
	
	    //bell number
		public static long cf (int n,int m)
		{
			// for m,n>1, the number m equal to the number thats on the n's left and left top corner
			if(m>n/2) m=n-m;
			int i;
			long a=1,b=1;
			for(i=n;i>n-m;i--)
				a*=i;
			for(i=2;i<=m;i++)
				b*=i;
			return a/b;
		}
		
		public static long bn(int n)
		{
			long t=0;
			int i;
			if(n==0) return 1; //In the Bell triangle if the first row is 1 (A1,1=1)
			else
			{
				// for n>1, at n row first number equal to the last number in n-1 row(An,1=An-1,n-1)
				for(i=0;i<=n-1;i++)
					t+=cf(n-1,i)*bn(i);
			}
			return t;
		}

		public void BellNumber(int n)
		{
			//bell triangle
			result=bn(n);
		}
		
		public void TriangleNumber(int n)
		{
			//triangle number
			
			long t;
			t=(n*(n+1))/2;
			result=t;
		}
		
		public void CatalanNumber(int n)
		{
			//Catalan number
			//the equation for Catalan number is Cn=(2n)!/(n+1)!*n!
			int i;
			long ans;
			long ans1=1;
			long ans2=1;
			long ans3=1;
			
			//This part calculate (2n)!
			for(i=0;i<2*n;i++)
			{
				ans1=ans1*(2*n-i);
			}
			
			//This part calculate (n+1)!
			for(i=0;i<(n+1);i++)
			{
				ans2=ans2*((n+1)-i);
			}
			
			//This part calculate n!
			for(i=0;i<n;i++)
			{
				ans3 = ans3 *(n-i);
			}
			
			// This part calculate out the result of Cn
			ans=ans1/(ans2*ans3);
			result=ans;
		}
		
		public long getResult()
		{
			return result;
		}
	}
