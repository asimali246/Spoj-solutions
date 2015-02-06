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


const int N = 666 ;
int t, h, w, n, i, H[N], W[N], dp[N][N] ;

int solve(int w, int h) {
	if( dp[w][h] != -1 )
		return dp[w][h] ;
	int res = h * w  ;
	for( int i = 1; i <= n; ++i ) {
		if( H[i] > h || W[i] > w ) 
			continue ;
		res = min( res, solve( w - W[i], h ) + solve( W[i], h - H[i] ) )  ;
		res = min( res, solve( w - W[i], H[i] ) + solve( w, h - H[i] ) ) ;
	}
	return dp[w][h] = res ;
}
int main() {
	scanf("%d", &t) ;
	while( t-- ) {
		scanf("%d %d", &w, &h) ;
		scanf("%d", &n) ;
		for( i = 1; i <= n; ++i )
			scanf("%d %d", &W[i], &H[i] ) ;
		memset(dp, -1, sizeof dp ) ;
		printf("%d\n", solve(w, h));
	}
	return 0 ;
}
