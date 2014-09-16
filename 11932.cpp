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

int t, n, vis[55], ans[55];
int dp[55][5];

int solve(int pos, int p) {
	if(pos > n) 
		return 1;
	if(dp[pos][p] != -1 )
		return dp[pos][p];
	int ans = 0;
	if(!p)
		ans += solve(pos + 1, 1);
	ans += solve(pos + 1, 0);
	return dp[pos][p] = ans;
}

int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d", &n);
		if( ans[n] ) {
			printf("%d\n", ans[n]);
			continue;
		}
		memset(dp, -1, sizeof dp);
		ans[n] = solve(1, 0);
		printf("%d\n", ans[n]);
	}
	return 0;
}
