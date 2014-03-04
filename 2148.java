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
        
        int t, nn;
        BigInteger s, n, x;
        t=in.nextInt();
        while(t-->0)
        {
            nn=in.nextInt();
            s=BigInteger.ZERO;
            for(int i=1;i<=nn;++i)
            {
                x=in.nextBigInteger();
                s=s.add(x);
            }
            n=BigInteger.valueOf(nn);
            if(s.mod(n).compareTo(BigInteger.ZERO)==0)
                System.out.println("YES");
            else
                System.out.println("NO");
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
