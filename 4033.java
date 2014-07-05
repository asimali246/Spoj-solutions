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
    boolean time=true;
    void solve(InputReader in){
        try{
            long start=System.currentTimeMillis();

            int t, n, i, ans;
            String a[]=new String[10100];

            t=in.nextInt();
            while(t-->0){
                n=in.nextInt();
                for(i=1;i<=n;++i)
                    a[i]=String.valueOf(in.next());
                Arrays.sort(a, 1, n+1);
                ans=1;
                for(i=2;i<=n;++i)
                    if(a[i].startsWith(a[i-1])){
                        ans=0;
                        break;
                    }
                if(ans==1)
                    System.out.println("YES");
                else
                    System.out.println("NO");
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
