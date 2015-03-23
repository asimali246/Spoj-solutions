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

typedef vector<int> vi ;
typedef pair<int, int> ii ;



const ll N = 3010 ;
ll t, n, m, dp[N][15], i, j, V[N][N] ;
ll a[N] ;

ll solve(int p, int c ) {
	if( p == n + 1 ) 
		return 0 ;
	if( c > m ) 
		return INF ;
	if( dp[p][c] != -1 ) 
		return dp[p][c] ;
	ll &ans = dp[p][c] ;
	ans = INF ;
	for( int j = p ; j <= n; ++j ) {
		ans = min( ans, V[p][j] + solve(j + 1, c + 1 ) ) ;
	}
	return ans ;
}

int main() {
	scanf("%lld", &t) ;
	while( t-- ) {
		scanf("%lld %lld", &n, &m ) ;
		for( i = 1; i <= n; ++i ) 
			scanf("%lld", &a[i] ) ;
		memset( dp, -1, sizeof dp ) ;
		sort( a + 1, a + n + 1 ) ;
		for( i = 1; i <= n; ++i ) {
			V[i][i] = 0 ;
			V[i][i + 1] = a[i + 1] - a[i] ;
			ll x = a[i + 1] ;
			ll y = a[i] ;
			int p, q;
			p = 1 ;
			q = 1 ;
			for( j = i + 2; j <= n; ++j ) {
				if( (j - i + 1) & 1 ) {
					x += a[j] - a[j - p] ;
					++p ;
				} else {
					x += a[j] ;
					y += a[j - q - 1] ;
					++q ;
				}
				V[i][j] = x - y ;
			}
		}
		printf("%lld\n", solve(1, 1) ) ;
	}
	return 0 ;
}
