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

const int N = 1010 ;
int t, n, i, a[N], dp[N][N], T[N], j, ans, ri[N] ;

void update(int x, int v) {
	while( x <= n ) {
		T[x] += v;
		x += (x & (-x) ) ;
	}
}
int query(int x) {
	int sum = 0 ;
	while( x > 0 ) {
		sum += T[x] ;
		x -= (x & (-x) ) ;
	}
	return sum ;
}
int solve(int l, int h) {
	if( l == h ) {
		return ri[l] ;
	}
	if( dp[l][h] != -1 ) 
		return dp[l][h] ;
	int &ans = dp[l][h] ;
	ans = INF ;
	int pos ;
	pos = query(ri[l]) + 1 ;
	update(ri[l], 1) ;
	ans = min(ans, pos * ( h - l + 1) + solve(l + 1, h) ) ;
	update(ri[l], -1) ;
	pos = query(ri[h]) + 1 ;
	update(ri[h], 1) ;
	ans = min(ans, pos * (h - l + 1) + solve(l, h - 1) ) ;
	update(ri[h], -1) ;
	return ans ;
}
int main() {
	scanf("%d", &t) ;
	while( t-- ) {
		scanf("%d", &n) ;
		for( i = 1; i <= n; ++i ) 
			scanf("%d", &a[i]), ri[a[i]] = i, T[i] = 0 ;
		for( i = 1; i <= n; ++i )
			for( j = 1; j <= n; ++j ) 
				dp[i][j] = -1 ;
		printf("%d\n", solve(1, n) ) ;
	}
	return 0 ;
}
