import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import java.awt.Rectangle;

public class Main {

    public static void main( String[] args ) {
        
        InputStream inputStream = System.in ;
        InputReader in = new InputReader( inputStream ) ;
        Solution solver = new Solution();
        solver.solve( in ) ;

    }

}

class cmp implements Comparator<Integer> {

    public int compare( Integer a, Integer b ) {

        return b.compareTo( a ) ;
    }
}

class Solution{

    boolean time = false ;
    int l, h, i, t, pos;
    BigInteger p[] ;
    BigInteger num ;
    void solve( InputReader in ) {
        
        try{
            
            long start=System.currentTimeMillis();
            
            int ans ;
            p = new BigInteger[10000] ;
            p[0] = BigInteger.ONE ;
            for( i = 1; ; ++i ) {
                p[i] = p[i - 1].multiply(BigInteger.valueOf(2) ) ;
                if( String.valueOf(p[i]).length() >= 1000 ) 
                    break ;
            }
            t = in.nextInt() ;
            while( t-- > 0 ) {
                num = in.nextBigInteger() ;
                search() ;
                ans = pos ;
                num = num.subtract( p[pos] ).add(BigInteger.ONE) ;
                while( true ) {
                    if( num.compareTo(BigInteger.ZERO) == 0 ) 
                        break ;
                    ++ans ;
                    search() ;
                    num = num.subtract( p[pos] ) ;
                }
                System.out.println( ans ) ;
            }
            long end=System.currentTimeMillis();
            if(time)
                System.out.println("Execution time: "+(double)(end-start)/1000.0);
        }
        catch(Exception e){
            System.out.println("Error: "+e);
        };
    }
    void search() {
        l = 0 ;
        h = i ;
        int m ;
        while( l <= h ) {
            m = (l + h) >> 1 ;
            if( p[m].compareTo( num ) > 0 ) {
                h = m - 1 ;
            }
            else {
                l = m + 1 ;
                pos = m ;
            }
        }
    }
}

class InputReader {

    public BufferedReader reader ;
    public StringTokenizer tokenizer ;
    
    public InputReader( InputStream stream ) {
        reader = new BufferedReader( new InputStreamReader( stream ) ) ;
        tokenizer = null ;
    }
    public String next() {
        while( tokenizer == null || !tokenizer.hasMoreTokens() ) {
            try{
                tokenizer = new StringTokenizer( reader.readLine() ) ;
            }catch( IOException e ) {
                throw new RuntimeException( e ) ;
            }
        }
        return tokenizer.nextToken() ;
    }
    public int nextInt() {
        return Integer.parseInt( next() ) ;
    }
    public long nextLong() {
        return Long.parseLong( next() ) ;
    }
    public BigInteger nextBigInteger() {
        return new BigInteger( next() ) ;
    }
    public String nextString() {
        return String.valueOf( next() ) ;
    }
}  
