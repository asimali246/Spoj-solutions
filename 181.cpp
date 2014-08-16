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

int t, o, nt, dp[25][80][1010], i, j, ox[1010], ni[1010], w[1010], k, ans, n;

int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d %d", &o, &nt);
		scanf("%d", &n);
		for( i = 1; i <= n; ++i )
			scanf("%d %d %d", &ox[i], &ni[i], &w[i]);
		for( i = 0; i <= 21; ++i )
			for( j = 0; j <= 79; ++j )
				dp[i][j][0] = INF;
		for( i = 0; i <= n; ++i )
			dp[0][0][i] = 0;
		for( k = 1; k <= n; ++k )
			for( i = 0; i <= 21; ++i )
				for( j = 0; j <= 79; ++j )
					dp[i][j][k] = min( dp[i][j][k-1], w[k] + dp[max(0, i - ox[k])][max(0, j - ni[k])][k-1]);
		ans = INF;
		for( i = o; i <= 21; ++i )
			for( j = nt; j <= 79; ++j )
				ans = min(ans , dp[i][j][n]);
		printf("%d\n", ans);
	}
	return 0;
}
