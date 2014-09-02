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

int n, dp[50][5];

int solve(int pos, int v) {
	if( pos > n ) 
		return 1;
	if( dp[pos][v] != -1 )
		return dp[pos][v];
	int ans;
	ans = solve( pos + 1, v );
	if( v - 1 >= 0 )
		ans += solve( pos + 1, v - 1);
	if( v + 1 <= 2 )
		ans += solve( pos + 1, v + 1);
	return dp[pos][v] = ans;
}
int main() {
	scanf("%d", &n);
	if( n == 0 )
		printf("1\n");
	memset(dp, -1, sizeof dp);
	--n;
	printf("%d\n", solve(1, 0) + solve( 1, 1 ) + solve( 1, 2 ) );
	return 0;
}
