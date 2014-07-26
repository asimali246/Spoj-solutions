import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import java.awt.Rectangle;
public class Main{
    public static void main(String[] args){
        InputStream inputStream=System.in;
        InputReader in=new InputReader(inputStream);
        Solution solver=new Solution();
        solver.solve(in);
    }
}
class cmp implements Comparator<Integer>{
    public int compare(Integer a, Integer b){
        return b.compareTo(a);
    }
}
class Solution{
    boolean time=false;
    void solve(InputReader in){
        try{
            long start=System.currentTimeMillis();

            String s;
            int i, l, flag;
            BigInteger ans=new BigInteger("0");
            BigInteger tmp=new BigInteger("0");
            while(true){
                s=in.nextString();
                if(s.charAt(0)=='*')
                    break;
                ans=BigInteger.ONE;
                l=s.length();
                for(i=0;i<l;++i)
                    if(s.charAt(i)=='Y'){
                        tmp=ans;
                        ans=tmp.multiply(BigInteger.valueOf(i+1)).divide(ans.gcd(BigInteger.valueOf(i+1)));
                    }
                flag=1;
                for(i=0;i<l;++i)
                    if(s.charAt(i)=='N')
                        if(ans.mod(BigInteger.valueOf(i+1)).compareTo(BigInteger.valueOf(0))==0)
                            flag=0;
                if(flag==1)
                    System.out.println(ans);
                else
                    System.out.println("-1");
            }                      

            long end=System.currentTimeMillis();
            if(time)
                System.out.println("Execution time: "+(double)(end-start)/1000.0);
        }catch(Exception e){
            System.out.println("Error: "+e);
        };
    }
}
class InputReader{
    public BufferedReader reader;
    public StringTokenizer tokenizer;
    public InputReader(InputStream stream){
        reader=new BufferedReader(new InputStreamReader(stream));
        tokenizer=null;
    }
    public String next(){
        while(tokenizer==null || !tokenizer.hasMoreTokens()) {
            try{
                tokenizer=new StringTokenizer(reader.readLine());
            }catch(IOException e){
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }
    public int nextInt(){
        return Integer.parseInt(next());
    }
    public long nextLong(){
        return Long.parseLong(next());
    }
    public BigInteger nextBigInteger(){
        return new BigInteger(next());
    }
    public String nextString(){
        return String.valueOf(next());
    }
}  
