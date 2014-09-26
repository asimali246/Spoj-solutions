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

const int N = 2010;
int la, lb, i, j, dp[N][N], k;
char a[N], b[N];

int solve(int l, int r) {
	if( l == la ) 
		return ( lb - r ) * k ;

	if( r == lb ) 
		return ( la - l ) * k ;

	if( dp[l][r] != -1 )
		return dp[l][r];

	int ans = INF;
	ans = min( ans, solve( l + 1, r + 1) + abs( a[l] - b[r] ) ) ;
	ans = min( ans, solve( l, r + 1) + k );
	ans = min( ans, solve( l + 1, r ) + k );
	return dp[l][r] = ans;
}

int main() {
	scanf("%s", a);
	scanf("%s", b);
	scanf("%d", &k);
	la = (int) strlen( a );
	lb = (int) strlen( b );
	memset(dp, -1, sizeof dp);
	printf("%d\n", solve( 0, 0 ));
	return 0;
}
