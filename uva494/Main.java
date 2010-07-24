mport java.io.*;

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
            String line ;
            while(null != (line = br.readLine()))
            {                
                int count = 0, len = line.length();
                boolean startWord = false;
                for (int i = 0 ; i < len ; ++i)
                {
                    char c = line.charAt(i);
                    if (!startWord && Character.isLetter(c))
                        startWord = true;
                    if (startWord && !(Character.isLetter(c)))
                    {
                        count++;
                        startWord = false;
                    }
                }               
              
                System.out.println(count);             
            }
        }
        catch (IOException e)
        {}

        return ;
    }

}

