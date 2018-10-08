package assg6_Chen;
/**
 * @author Huan-Yun Chen
 * CSCI 2540-001
 * 
 * @declare title name of the DVD
 * @declare category the category for the DVD
 * @declare runTime the total length of the DVD
 * @declare year the year when DVD was publish
 * @declare price the price of the DVD
 * 
 * This class provide all the information that a DVD has
 */
public class DVD {

	String title;
	String category;
	String runTime;
	String year;
	String price;
//Constructor
	/**
	 * 
	 * @param titleName name of the DVD
	 * @param categoryName the category for the DVD
	 * @param run the total length of the DVD
	 * @param yearT the year when DVD was publish
	 * @param priceM the price of the DVD
	 */
	public DVD(String titleName, String categoryName, String run, String yearT, String priceM)
	{
		title= titleName;
		category= categoryName;
		runTime= run;
		year= yearT;
		price= priceM;
	}
//Method
	/**
	 * 
	 * @return title return the title of the DVD
	 */
	public String getTitle()
	{
		return title;
	}
	/**
	 * 
	 * @return category return the category name
	 */
	public String getCategory()
	{
		return category;
	}
	/**
	 * 
	 * @return runTime return the runTime value
	 */
	public String getRunTime()
	{
		return runTime;
	}
	/**
	 * 
	 * @return year return the year value
	 */
	public String getYear()
	{
		return year;
	}
	/**
	 * 
	 * @return price return the price value
	 */
	public String getPrice()
	{
		return price;
	}
	/**
	 * 
	 * @param categoryName category's Name
	 * change the category value
	 */
	public void setCategory(String categoryName)
	{
		category = categoryName;
	}
	/**
	 * 
	 * @param run runTime value
	 * change the runTime value
	 */
	public void setRunTime(String run)
	{
		runTime = run;
	}
	/**
	 * 
	 * @param yearT year's value
	 * change the year value
	 */
	public void setYear(String yearT)
	{
		year = yearT;
	}
	/**
	 * 
	 * @param priceM price value
	 * change the price of the DVD
	 */
	public void setPrice(String priceM)
	{
		price = priceM;
	}
	/**
	 * @return return all the information for the DVD
	 */
	public String toString()
	{
		String titleName;
		String categoryName; 
		String run;
		String yearT;
		String priceM;
		titleName = title;
		categoryName = category;
		run = runTime;
		yearT = year;
		priceM = price;
		return titleName+"\n"+categoryName+"\n"+run+"\n"+yearT+"\n"+priceM;
	}
	/**
	 * 
	 * @param a object to compare with
	 * @return return true when they have the same name
	 * 		   return false when object is not the same or is not the DVD
	 */
	public boolean equal(Object a)
	{
		Class c = a.getClass();
		if(c.getName()!= "assg6_Chen.DVD")
		{
			return false;
		}
		else
		{
			DVD b = DVD.class.cast(a);
			String name = b.getTitle();
			if(title == name)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	/**
	 * 
	 * @param example the DVD to compare with
	 * compare two DVD in alphabetical order
	 */
	public void compareTo(DVD example)
	{
		int compareResult;
		String titleName =example.title;
		compareResult = title.compareTo(titleName);
		//i'm confuse about what i should do after the comparison
		if(compareResult < 0)
		{
			
		}
		else if(compareResult>0)
		{
			
		}
	}
}
