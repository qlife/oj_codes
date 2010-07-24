import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {

    /**
     * @param args
     */
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Main myWork = new Main();  // create a dinamic instance
        myWork.Begin();            // the true entry point

    }
    
    
    void Begin()
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try
        {
            String line1,line2 ;
            while (true)
            {
                line1 = br.readLine(); line2 = br.readLine();
                if (null == line1) break;           
                BigInteger bg1 = new BigInteger(line1);
                BigInteger bg2 = new BigInteger(line2);
                
                BigInteger product = bg1.multiply(bg2);
                System.out.println(product.toString());
                bg1 = null; bg2 = null;
                
            }            
        }
        catch (IOException e)
        {}

        return ;
    }

}
