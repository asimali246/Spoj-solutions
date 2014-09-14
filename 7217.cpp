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

int n, m, i, j, s[22][22], dp[22][22], x, y, ans = -INF;

int solve(int x, int y) {
	if(x > n || y > m ) 
		return INF;
	if(x == n && y == m )
		return s[x][y];
	if(dp[x][y] != -1 )
		return dp[x][y];
	int temp;
	temp = min(solve(x + 1, y) + s[x][y], solve(x, y + 1) + s[x][y]);
	return dp[x][y] = temp;
}
int main() {
	scanf("%d %d", &n, &m);
	scanf("%d %d", &x, &y);
	for( i = 1; i <= n; ++i )
		for( j = 1; j <= m; ++j )
			scanf("%d", &s[i][j]);
	memset(dp, -1, sizeof dp);
	ans = solve(x, y);
	ans = 2 * s[x][y] - ans;
	if(ans >= 0)
		printf("Y %d\n", ans);
	else
		printf("N\n");
	return 0;
}
