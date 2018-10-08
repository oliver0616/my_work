
public class pi {
	
	private static long result;

	public void archimedes (double n)
	{
		double t;
		t = n*Math.sin(180/n);
		t=result;
	}

	public void leibniz (int n)
	{
		double t;
		for(int i=0;i<n;i++)
		{
			t = (-1)^n/(2*n)+1;
		}
		t=result;
	}
	
	public void wallis(double n)
	{
		double t;
		for(int i=0;i<n;i++)
		{
			t= (2*n/(2*n-1))*(2*n/(2*n+1));
		}
		t=result;	
	}
	
	public void  monteCarlo(double n)
	{
		double t;
		
			t= n*Math.PI;
		
	}
	
	
	
	
	public long getResult()
	{
		return result;
	}
	
	
}
