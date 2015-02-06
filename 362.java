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
    void solve( InputReader in ) {
        
        try{
            
            long start=System.currentTimeMillis();
            
            int t, i, j ;
            String ans  ;
            BigInteger k, v ;
            BigInteger p[] = new BigInteger[250] ;
            BigInteger sum[] = new BigInteger[250] ;
            int n[] = new int[]{0, 1, 2, 5, 6, 8, 9} ;
            p[0] = BigInteger.ONE ;
            sum[0] = BigInteger.ZERO ;

            for( i = 1; i < 250 ; ++i ) {
                p[i] = p[i - 1].multiply( BigInteger.valueOf(7) ) ;
                sum[i] = p[i] ;
            }
            t = in.nextInt() ;
            while( t-- > 0 ) {
                
                k = in.nextBigInteger() ;
                
                for( i = 1; i < 250 ; ++i ) 
                    if( sum[i].compareTo(k) > 0 ) 
                        break ;
                if( i == 1 ) {
                    ans = String.valueOf( n[ Value(k) ] ) ;
                }
                else {
                    if( sum[i].compareTo(k) == 0 ) {
                        for( j = 1; j <= i; ++j ) 
                            System.out.print("6") ;
                        System.out.println() ;
                        continue ; 
                    }
                    ans = "" ;
                    --i ;
                    while( i != 0 ) {
                        for( j = 0; j < 7; ++j ) {
                            if( k.compareTo( p[i] ) >= 0 ) {
                                k = k.subtract( p[i] ) ;
                            }
                            else
                                break ;
                        }
                        // System.out.println(j) ;
                        ans += String.valueOf( n[j] ) ;
                        --i ;
                    }
                    ans += String.valueOf( n[ Value(k) ] ) ;
                }
                for( i = ans.length() - 1; i >= 0 ; --i ) {
                    if( ans.charAt(i) == '9' ) 
                        System.out.print("6") ;
                    else
                    if( ans.charAt(i) == '6' ) 
                        System.out.print("9") ;
                    else
                        System.out.print(ans.charAt(i) ) ;
                }
                System.out.println() ;
            }

            long end=System.currentTimeMillis();
            if(time)
                System.out.println("Execution time: "+(double)(end-start)/1000.0);
        }
        catch(Exception e){
            System.out.println("Error: "+e);
        };
    }
    int Value(BigInteger x) {
        
        if( x.compareTo( BigInteger.valueOf(0) ) == 0 )
            return 0 ;
        if( x.compareTo( BigInteger.valueOf(1) ) == 0 )
            return 1 ;
        if( x.compareTo( BigInteger.valueOf(2) ) == 0 )
            return 2 ;
        if( x.compareTo( BigInteger.valueOf(3) ) == 0 )
            return 3 ;
        if( x.compareTo( BigInteger.valueOf(4) ) == 0 )
            return 4 ;
        if( x.compareTo( BigInteger.valueOf(5) ) == 0 )
            return 5 ;
        if( x.compareTo( BigInteger.valueOf(6) ) == 0 )
            return 6 ;
        return 10 ;
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
