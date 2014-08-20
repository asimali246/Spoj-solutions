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
#include <stdint.h>
#include <unistd.h>
 
 using namespace std;
 
#define ll long long int
#define INF 1000000000
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;

int t, i, j, a[22][22], n;
ll dp[1<<20];

inline int Sum(int mask){
	int ans = 0;
	while( mask ){
		if( mask & 1 )
			++ans;
		mask >>= 1;
	}
	return ans;
}

ll solve(int mask) {
	int pos = __builtin_popcount(mask);
	if( pos >= n ) {
		if( mask == ( 1 << n ) - 1 )
			return 1;
		return 0;
	}
	if( dp[mask] != -1 )
		return dp[mask];
	ll ans = 0;
	++pos;
	for( int j = 1; j <= n; ++j )
		if( a[pos][j] && !( mask & ( 1 << ( j - 1 ) ) ) )
			ans += solve( mask | ( 1 << ( j - 1 ) ) );
	return dp[mask] = ans;
}

int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d", &n);
		for( i = 1; i <= n; ++i )
			for( j = 1; j <= n; ++j )
				scanf("%d", &a[i][j]);
		for( i = 0; i < ( 1 << n ); ++i )
			dp[i] = -1;
		printf("%lld\n", solve(0));
	}
	return 0;
}
