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

int n, i, dp[1010][1010], a[1010], b[1010];

int solve(int pos, int p ) {
	if( pos == n + 1 ) {
		return 0;
	}
	
	if( dp[pos][p] != -1 )
		return dp[pos][p];
	if( pos == 1 )
		p = a[pos];
	int ans;
	ans = abs(p - a[pos]) + b[pos] + solve(pos + 1, a[pos]);
	if( pos == 1 ) 
		p = b[pos];
	ans = max( ans, abs( p - b[pos]) + a[pos] + solve(pos + 1, b[pos]));
	return dp[pos][p] = ans;
}
int main() {
	scanf("%d", &n);
	for( i = 1; i <= n; ++i )
		scanf("%d %d", &a[i], &b[i]);
	memset(dp, -1, sizeof dp);
	printf("%d\n", solve( 1, 0) );
	return 0;
}
