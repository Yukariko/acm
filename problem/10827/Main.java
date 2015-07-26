import java.util.Scanner;
import java.math.BigDecimal;
 
public class Main 
{
    public static void main(String[] args) 
    {
        Scanner input=new Scanner(System.in);
        String A;
        int B;
        A = input.next();
        B = input.nextInt();

        BigDecimal a = new BigDecimal(A);

        a = a.pow(B);
        
        System.out.print(a.toPlainString());
        
        input.close();
    }
}