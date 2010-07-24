import java.io.*;
import java.util.*;

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
        TreeMap<String,Integer> countries = new TreeMap<String,Integer>();
        HashMap<String,Integer> equalFilter = new HashMap<String,Integer>();
        try
        {
            
            String line ;
            line = br.readLine();
            int n = Integer.parseInt(line);
            for (int i = 0 ; i < n ; ++i)
            {
                line = br.readLine();
                if (equalFilter.containsKey(line))
                    continue;
                else
                    equalFilter.put(line, 1);
                
                StringTokenizer st = new StringTokenizer(line);
                String key = st.nextToken();                
                
                if (countries.containsKey(key))
                {
                    int curr = countries.get(key) ;
                    curr ++;
                    countries.put(key, curr);
                }
                else
                {
                    countries.put(key,1);
                }
            }    
             
            Set<String> c = countries.keySet();
            Iterator<String> itr = c.iterator();
            while(itr.hasNext())
            {
                String itrkey = itr.next();
                StringBuffer sb = new StringBuffer();
                sb.append(itrkey).append(" ").append(countries.get(itrkey));
                System.out.println(sb.toString());
            }              
            
        }
        catch (IOException e)
        {}

        return ;
    }


}

