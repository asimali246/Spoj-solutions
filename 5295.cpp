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

int t, d, n, k, dp[111][111][2], i, j;

int solve(int pos, int b, int p) {
	if( pos == n + 1 ){
		if( b == k )
			return 1;
		return 0;
	}
	
	if( dp[pos][b][p] != -1 )
		return dp[pos][b][p];

	int ans = 0;
	ans += solve( pos + 1, b, 0);
	if( p )
		ans += solve( pos + 1, b + 1, 1);
	else
		ans += solve( pos + 1, b, 1);
	return dp[pos][b][p] = ans;
}

int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d %d %d", &d, &n, &k);
		memset(dp, -1, sizeof dp);
		printf("%d %d\n", d, solve(1, 0, 0));
	}
	return 0;
}
