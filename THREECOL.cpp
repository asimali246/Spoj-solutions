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



const int N = 1e4 + 10 ;
int t, i, mn, mx, l, v, u, n, s, j;
vector<int> g[N] ;
char S[N] ;
stack<int> st ;
ii dp[N][4] ;


ii combine(ii a, ii b, ii c) {
	ii temp ; 
	temp.first = max( a.first, max( b.first, c.first ) ) ;
	temp.second = min( a.second, min( b.second, c.second ) ) ;
	return temp ;
}

void take(ii &ans, ii temp ) {
	ans.first = max( ans.first, temp.first ) ;
	ans.second = min( ans.second, temp.second ) ;
}

ii solve(int u, int c) {
	if( (int) g[u].size() == 0 ) {
		if( c == 2 ) 
			return ii(1, 1) ;
		return ii(0, 0) ;
	}
	if( dp[u][c].first != -1 )
		return dp[u][c] ;
	ii &ans = dp[u][c] ;
	ans.first = -INF ;
	ans.second = INF ;
	s = (int) g[u].size() ;
	ii temp ;
	if( s == 1 ) {
		int v = 0 ;
		if( c == 2 ) 
			v = 1 ;
		for( int j = 1; j <= 3; ++j ) {
			if( j != c ) {
				temp = solve(g[u][0], j) ;
				temp.first += v ;
				temp.second += v ;
				take( ans, temp ) ;
			}
		}
	}
	else {
		ii a, b ;
		if( c == 1 ) {
			a = solve( g[u][0], 2 ) ;
			b = solve( g[u][1], 3 ) ;
			temp.first = a.first + b.first ;
			temp.second = a.second + b.second ;
			take( ans, temp ) ;
			a = solve( g[u][0], 3 ) ;
			b = solve( g[u][1], 2 ) ;
			temp.first = a.first + b.first ;
			temp.second = a.second + b.second ;
			take( ans, temp ) ;
		}
		if( c == 3 ) {
			a = solve( g[u][0], 1 ) ;
			b = solve( g[u][1], 2 ) ;
			temp.first = a.first + b.first ;
			temp.second = a.second + b.second ;
			take( ans, temp ) ;
			a = solve( g[u][0], 2 ) ;
			b = solve( g[u][1], 1 ) ;
			temp.first = a.first + b.first ;
			temp.second = a.second + b.second ;
			take( ans, temp ) ;
		}
		if( c == 2 ) {
			a = solve( g[u][0], 1 ) ;
			b = solve( g[u][1], 3 ) ;
			temp.first = a.first + b.first + 1;
			temp.second = a.second + b.second + 1;
			take( ans, temp ) ;

			a = solve( g[u][0], 3 ) ;
			b = solve( g[u][1], 1 ) ;
			temp.first = a.first + b.first + 1;
			temp.second = a.second + b.second + 1;
			take( ans, temp ) ;
		}
	}
	return ans ;
}

int main() {
	scanf("%d", &t) ;
	while( t-- ) {
		scanf("%s", S ) ;
		st = stack<int>() ;
		l = (int) strlen( S ) ;
		for( i = 1; i <= l; ++i ) 
			g[i].clear() ;
		st.push( 1 ) ;
		n = 2 ;
		if(l == 0) {
			printf("0 0\n");
			continue ;
		}
		for( i = 0; i < l; ++i ) {
			v = S[i] - '0' ;
			u = st.top() ; st.pop() ;
			while( v ) {
				g[u].push_back( n++ ) ;
				st.push( n - 1 ) ;
				v-- ;
			}
		}
		--n ;
		for( i = 1; i <= n; ++i ) {
			for( j = 1; j <= 3; ++j ) 
				dp[i][j].first = dp[i][j].second = -1 ;
		}
		ii ans = combine(solve(1, 1), solve(1, 2), solve(1, 3) ) ;
		printf("%d %d\n", ans.first, ans.second ) ;
	}
	return 0 ;
}
