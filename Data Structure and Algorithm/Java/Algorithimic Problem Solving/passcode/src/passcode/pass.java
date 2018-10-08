package passcode;

import java.util.Scanner;

public class pass {

	public static void main(String[] args) {
	
	int plain_len;
	int key_len;
	int i=0,j=0,k=0;
	char cm,ck,cl,ce;
	int cm_code,ck_code,ce_code;
	
	
	int inc,dec;
	String encription="";
	String decription= "";
		
	String plain;
	String key_value;
	String temp;
	Scanner scan;
	
	scan = new Scanner(System.in);
	System.out.println("key in your message");
	plain = scan.nextLine();
	plain_len = plain.length();
	System.out.println("Key in your key");
	key_value = scan.nextLine();
	key_len = key_value.length();
	
	if (key_len < plain_len)
		{
		i = plain_len / key_len;
		j = plain_len % key_len;
		temp = "";
		for(k=1; k<=i; k++)
			{
			temp = temp + key_value;
			}
        key_value = temp + key_value.substring(0, j);
		}
	else
		{
		key_value = key_value.substring(0, plain_len);
		}
	    
	
	
	for(i=0;i<plain_len;i++)
		{
			cm= plain.charAt(i);
			ck= key_value.charAt(i);
			if (cm == 32)
				cm_code = 26;
			else
				cm_code = cm-97;
			if (ck == 32)
				ck_code = 26;
			else
				ck_code = ck-97;
			
			inc = (cm_code+ck_code)%27;
			if (inc == 26)
			encription= encription + "B";
			else
			{
				cl = (char)(inc + 97);
				encription = encription + cl;
			}
		}
		System.out.println("Your encription message is");
		System.out.println(encription);
		
		System.out.println("Now going to decription");
		
	for(i=0;i<plain_len;i++)
		{
		ce= encription.charAt(i);
		ck= key_value.charAt(i);
		if (ce == 66)
			ce_code = 26;
		else
			ce_code = ce-97;
		if (ck == 66)
			ck_code = 26;
		else
			ck_code = ck-97;
		
		
		if (ce-ck>=0)
			dec = ce_code-ck_code;
		else
			dec = 27+(ce_code-ck_code);
		if (dec == 26)
			decription= decription +" ";
		else
			{
			ce = (char)(dec + 97);
			decription = decription + ce;
			}
		}
	System.out.println("Your decription message is");
	System.out.println(decription);
	
	
	}

}