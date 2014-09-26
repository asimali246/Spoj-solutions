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
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 111 ;
int tt, n, t, T[N][N], R[N][N], i, j;
ii dp[N][333], ans;


ii solve(int p, int l) {
	if( l < 0 )
		return ii( INF, INF );
	if( p == n ) 
		return ii( 0, 0 );
	if( dp[p][l].first != -1 )
		return dp[p][l];
	ii temp;
	temp.first = temp.second = INF;
	for( int j = 1; j <= n; ++j ) {
		if( j != p ) {
			ii ret = solve( j, l - T[p][j] );
			if( ret.second + R[p][j] < temp.second ) 
				temp.first = T[p][j] + ret.first, temp.second = R[p][j] + ret.second;
		}
	}
	return dp[p][l] = temp;
}

int main() {
	scanf("%d", &tt);
	while( tt-- ) {
		scanf("%d %d", &n, &t);
		for( i = 1; i <= n; ++i )
			for( j = 1; j <= n; ++j )
				scanf("%d", &T[i][j]);
		for( i = 1; i <= n; ++i )
			for( j = 1; j <= n; ++j )
				scanf("%d", &R[i][j]);
		memset(dp, -1, sizeof dp);
		ans = solve( 1, t );
		if( ans.first == INF )
			printf("-1\n");
		else
			printf("%d %d\n", ans.second, ans.first );
	}
	return 0;
}
