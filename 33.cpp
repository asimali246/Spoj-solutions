#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <set>
#include <cstring>
#include <iomanip>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <string>
#include <vector>
#include <new>
#include <bitset>
#include <ctime>
#include <cassert>
#include <stdint.h>
#include <unistd.h>
 
 using namespace std;
 
#define ll long long int
#define INF 1000000000
#define PI acos(-1.0)
#define EPS 1e-9
 
template < typename X > X gcd( X a, X b ) { if( !b ) return a ; else return gcd(b, a%b) ; }
 
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 88 ;
int t, n, m, i, j, dp[N][N], trace[N][N] ;
char a[N], b[N] ;
string temp ;
vector<string> ans; 
bool space = false; 
map<pair<string, ii> , int > mp ;

inline bool invalid( int x, int y ) {
	if( x == 0 || y == 0 || x > n || y > m ) 
		return false ;
	return true ;
}

void solve(int x, int y, string s) {
	if( !invalid( x, y ) ) {
		temp = s ;
		reverse( temp.begin(), temp.end() ) ;
		ans.push_back( temp ) ;
		return ;
	}
	if( mp.count( make_pair(s, ii( x, y ) ) ) != 0 ) 
		return ;

	mp[ make_pair(s, ii( x, y ) ) ] = 1 ;

	if( trace[x][y] & 1 ) {
		if( a[x - 1] == b[y - 1] ) 
			solve( x - 1, y - 1, s + a[x - 1] );
		else
			solve( x - 1, y - 1, s ) ;
	}

	if( trace[x][y] & 2 ) {
		solve( x - 1, y , s ) ;
	}

	if( trace[x][y] & 4 ) {
		solve( x , y - 1, s ) ;
	}

	return ;

}

int main() {
	scanf("%d", &t);
	while( t-- ) {

		scanf("%s", a );
		scanf("%s", b ) ;

		n = (int) strlen( a ) ;
		m = (int) strlen( b ) ;

		mp.clear() ;

		ans.clear();

		for( i = 1; i <=n; ++i ) {
			for( j = 1; j <= m; ++j ) {
				trace[i][j] = 1 ;
				dp[i][j] = dp[i - 1][j - 1] + ( ( a[ i - 1 ] == b[ j - 1 ] ) ? 1 : 0 ) ;
				if( dp[i][ j - 1 ] > dp[i][j] )  {
					dp[i][j] = dp[i][ j - 1 ] ;
					trace[i][j] = 4 ;
				}
				else
				if( dp[i][j - 1] == dp[i][j] ) {
					trace[i][j] = 5 ;
				} 

				if( dp[i - 1 ][j] > dp[i][j] ) {
					dp[i][j] = dp[i - 1][j] ;
					trace[i][j] = 2 ;
				}
				else
				if( dp[i - 1][j] == dp[i][j] ) {
					trace[i][j] |= 2 ;
				}
			}
		}

		solve( n, m, "" ) ;
		sort( ans.begin(), ans.end() ) ;
		if( space ) 
			putchar('\n') ;
		space = true ;
		printf("%s\n", ans[0].c_str() );
		for( i = 1; i < (int) ans.size(); ++i ) {
			if( strcmp( ans[i - 1].c_str(), ans[i].c_str() ) != 0  ) 
				printf("%s\n", ans[i].c_str() ) ; 
		}
	}
	return 0 ;
}
