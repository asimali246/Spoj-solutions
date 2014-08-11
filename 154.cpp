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
#define INF 2147483647
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;

int t, n, i, a[222], dp[222];

int solve(int pos) {
	if( pos == n+1 )
		return 0;
	if( dp[pos] != -1)
		return dp[pos];
	int ans = INF;
	if( a[pos] == 0)
		ans = min( ans, 1 + solve(pos+1));
	int p, q;
	p = q = 0;
	for(int j = pos; j <= n; ++j ) {
		if(a[j] == 1)
			++p;
		else
			++q;
		if( p > q )
			ans = min( ans, solve(j + 1));
	}
	return dp[pos] = ans;
}

int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d", &n);
		getchar();
		for( i = 1; i <= n; ++i )
			a[i] = getchar() - '0';
		getchar();
		for( i = 1; i <= n; ++i )
			dp[i]=-1;
		printf("%d\n", n - solve(1));
	}
	return 0;
}
