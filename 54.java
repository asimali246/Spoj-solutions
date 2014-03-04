import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import java.awt.Rectangle;
public class Main 
{
    public static void main(String[] args)
    {
        InputStream inputStream=System.in;
        InputReader in=new InputReader(inputStream);
        Solution solver=new Solution();
        solver.solve(in);
    }
}
class Solution
{
    boolean time=false;
    void solve(InputReader in)
    {
        try{
        long start=System.currentTimeMillis();
        
        int t;
        BigInteger s, b;
        t=10;
        while(t-->0)
        {
            s=in.nextBigInteger();
            b=in.nextBigInteger();
            System.out.println(s.add(b).divide(BigInteger.valueOf(2)));
            System.out.println(s.subtract(b).divide(BigInteger.valueOf(2)));
        }

        long end=System.currentTimeMillis();
        if(time)
            System.out.println("Execution time: "+(double)(end-start)/1000.0);
        }catch(Exception e){
        };
    }
}
class InputReader 
{
    public BufferedReader reader;
    public StringTokenizer tokenizer;
 
    public InputReader(InputStream stream) 
    {
        reader=new BufferedReader(new InputStreamReader(stream));
        tokenizer=null;
    }
 
    public String next() 
    {
        while(tokenizer==null || !tokenizer.hasMoreTokens()) 
        {
            try
            {
                tokenizer=new StringTokenizer(reader.readLine());
            }catch(IOException e)
            {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }
 
    public int nextInt()
    {
        return Integer.parseInt(next());
    }
    public long nextLong()
    {
        return Long.parseLong(next());
    }
    public BigInteger nextBigInteger()
    {
        return new BigInteger(next());
    }
    public String nextString()
    {
        return String.valueOf(next());
    }
}  
