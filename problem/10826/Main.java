import java.util.Scanner;
import java.math.BigInteger;
 
 
public class Test 
{
    public static void main(String[] args) 
    {
        Scanner input=new Scanner(System.in);
        int N;
        N = input.nextInt();
        
        BigInteger a, b;
        
        a = new BigInteger("0");
        b = new BigInteger("1");
      
        for(int i=0; i < N; i++)
        {
        	b = b.add(a);
        	a = b.subtract(a);
        }
        
        System.out.print(a.toString());
        
        input.close();
    }
}