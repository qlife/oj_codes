import java.io.*;
import java.util.*;
import java.math.BigInteger;

// Change filename to Main.java otherwise javac will complain.

class Main
{

    BigInteger [] Cn = new BigInteger[1001];

    public static void main (String args[])  // entry point from OS
    {
        Main myWork = new Main();  // create a dinamic instance
        myWork.Begin();            // the true entry point
        //myWork.printNum();
    }

    Main()
    {
        for (int j = 1 ; j < Cn.length ; ++j)
            Cn[j] = BigInteger.ZERO;
        Cn[0] = BigInteger.ONE;
        preCompute();
    }

    void preCompute()
    {
        for (int n = 1 ; n < 1001 ; ++n)
        {
            for (int i = 0 ; i < n ; ++i)
            {
                BigInteger mul = Cn[i].multiply(Cn[n-1-i]);
                Cn[n] = Cn[n].add(mul);
            }
        }
    }

    void printNum()
    {
        for (int i = 0 ; i < Cn.length ; ++i)
            System.out.println(Cn[i].toString());
    }

    void Begin()
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try 
        {
            String line ;
            while(null != (line = br.readLine()))
            {
                StringTokenizer st = new StringTokenizer(line);
                int i = Integer.parseInt(st.nextToken());
                System.out.println(Cn[i].toString());
            }
        }
        catch (IOException e)
        {}
        
        return ;
    }
}

