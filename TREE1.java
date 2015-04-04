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

class Pair {
    BigInteger x ;
    int n ;
}
class Solution{

    boolean time = false ;

    ArrayList g[] = new ArrayList[33] ;
    int t, n, i, root, p, j;
    int a[] = new int[33] ;
    BigInteger C[][] = new BigInteger[33][33] ;
    BigInteger F[] = new BigInteger[33] ;
     
    void solve( InputReader in ) {
        
        try{
            
            long start=System.currentTimeMillis();

            F[0] = BigInteger.ONE ;
            for( i = 1; i <= 30; ++i ) 
                F[i] = F[i - 1].multiply( BigInteger.valueOf(i) ) ;

            for( i = 1; i <= 30; ++i ) {
                for( j = 1; j <= i; ++j ) {
                    C[i][j] = getResult(i, j) ;
                }
            }
            
            t = in.nextInt() ;
            while( t-- > 0 ) {
                for( i = 1; i <= 30; ++i ) 
                    g[i] = new ArrayList() ;
                n = in.nextInt() ;
                for( i = 1; i <= n; ++i ) 
                    a[i] = in.nextInt() ;
                root = a[1] ;
                p = 2 ;
                Construct( root, 1, 30 ) ;
                Pair ans = Calculate( root ) ;
                System.out.println( ans.x ) ;
            }
            
            long end=System.currentTimeMillis();
            if(time)
                System.out.println("Execution time: "+(double)(end-start)/1000.0);
        }
        catch(Exception e){
            System.out.println("Error: "+e);
        };
    }
    Pair Calculate(int u) {
        BigInteger ans ;
        Pair temp ;
        temp = new Pair() ;
        if( g[u].size() == 0 ) {
            temp.x = BigInteger.ONE ;
            temp.n = 1 ;
            return temp ;
        }
        if( g[u].size() == 1 ) {
            temp = Calculate( (int)g[u].get(0) ) ;
            temp.n++ ;
            return temp ;
        }
        int p, q ;
        temp = Calculate( (int)g[u].get(0) ) ;
        ans = temp.x ;
        p = temp.n ;
        temp = Calculate( (int)g[u].get(1) ) ;
        ans = ans.multiply( temp.x ) ;
        q = temp.n ;
        ans = ans.multiply( C[p + q][p] ) ;
        temp.x = ans ;
        temp.n = p + q + 1 ;
        return temp ;
    }
    
    BigInteger getResult(int n, int r) {
        BigInteger ans ;
        ans = F[n] ;
        ans = ans.divide( F[r] ) ;
        ans = ans.divide( F[n - r] ) ;
        return ans ;
    }

    void Construct(int u, int L, int R) {
        if( p > n ) 
            return ;
        if( a[p] >= L && a[p] < u ) {
            ++p ;
            g[u].add( a[p - 1] ) ;
            Construct( a[p - 1], L, u - 1 ) ;
        }
        if( p > n ) 
            return ;
        if( a[p] > u && a[p] <= R ) {
            ++p ;
            g[u].add( a[p - 1] ) ;
            Construct( a[p - 1], u + 1, R ) ;
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
