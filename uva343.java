/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author qlife
 */
import java.math.BigInteger;
import java.io.*;
import java.util.*;

public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main (String[] args) {
        // TODO code application logic here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try
        {
            String line ;
            while(null != (line = br.readLine()))
            {
                StringTokenizer st = new StringTokenizer(line);
                String val1 = st.nextToken();
                String val2 = st.nextToken();
                basesNumber num1 = new basesNumber(val1);
                basesNumber num2 = new basesNumber(val2);               
                boolean weGotAnswer = false;

                for (int i=num1.getSmallestBase() ; i<=36 ; ++i)
                {
                    for (int j=num2.getSmallestBase(); j<=36 ; ++j)
                    {
                        if (num1.bases[i].compareTo(num2.bases[j]) == 0)
                        {
                            //System.out.println("12 (base 3) = 5 (base 6)")
                            StringBuffer sb = new StringBuffer("");
                            sb.append(val1).append(" (base ").append(i).append(") = ");
                            sb.append(val2).append(" (base ").append(j).append(")");
                            System.out.println(sb.toString());
                            weGotAnswer = true;
                        }
                        if (weGotAnswer) break;
                    }
                    if (weGotAnswer) break;
                }

                if (!weGotAnswer)
                {
                    //123 is not equal to 456 in any base 2..36
                    StringBuffer sb = new StringBuffer("");
                    sb.append(val1).append(" is not equal to ").append(val2)
                            .append(" in any base 2..36");
                    System.out.println(sb.toString());
                }
            }
        }
        catch (IOException e)
        {}

        return ;
    }

    }

class basesNumber {
    public BigInteger [] bases = new BigInteger[37];
    private int smallestBase = -1;

    basesNumber(String literal)
    {
        char maxCh = '0';
        for (int i=0 ; i<literal.length() ; ++i)
            if (literal.charAt(i) > maxCh)
                maxCh = literal.charAt(i);

        if (maxCh == '0')
            smallestBase = 2;
        else if ((maxCh > '0') && (maxCh <= '9'))
            smallestBase = maxCh - '0' + 1;
        else if ((maxCh >= 'A') && (maxCh <= 'Z'))
            smallestBase = maxCh - 'A' + 10 + 1;

        for (int j=smallestBase ; j<= 36 ; ++j)
            bases[j] = new BigInteger(literal,j);
    }

    public int getSmallestBase()
    {
        return smallestBase;
    }

}





