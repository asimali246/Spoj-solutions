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

int t, n ;
ll dp[33][10] ;

ll solve(int p, int mask, int rm, int rt) {
	if( p == n ) {
		return 1;
	}
	if( dp[p][mask] != -1 )
		return dp[p][mask] ;
	ll ans = 0;
	for( int j = 0; j < 3; ++j ) {
		if( ( mask | ( 1 << j ) ) != 7 ) {
			int tm = mask ;
			if( rm != -1 && rt != rm ) {
				tm &= ~(1 << rm) ;
			} 
			ans += solve( p + 1, tm | ( 1 << j ) , rt, j ) ;
		}
	}
	return dp[p][mask] = ans ;
}

int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d", &n);
		memset(dp, -1, sizeof dp);
		printf("%lld\n", solve(0, 0, -1, -1));
	}
	return 0;
}
