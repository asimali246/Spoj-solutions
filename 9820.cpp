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

int t, n, a[22], d[22], b[22], dp[22][5], i;

int solve(int pos, int p) {
	if( pos == n + 1) {
		return 0;
	}
	if( dp[pos][p] != -1 ) 
		return dp[pos][p];
	int ans = 0;
	if( p == 1 ) {
		ans = d[pos] + solve(pos + 1, 2);
		ans = min( ans, b[pos] + solve(pos + 1, 3));
	}
	else
	if( p == 2 ) {
		ans = a[pos] + solve(pos + 1, 1);
		ans = min( ans, b[pos] + solve(pos + 1, 3));
	}
	else {
		ans = a[pos] + solve( pos + 1, 1);
		ans = min( ans, d[pos] + solve(pos + 1, 2));
	}
	return dp[pos][p] = ans;
}
int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d", &n);
		for(i = 1;i <= n; ++i )
			scanf("%d %d %d", &a[i], &d[i], &b[i]);
		memset(dp, -1, sizeof dp);
		printf("%d\n", min(a[1] + solve(2, 1), min(d[1] + solve(2, 2), b[1] + solve(2, 3))));
	}
	return 0;
}
