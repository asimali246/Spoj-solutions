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

const int N = 1<<14;
ll t, n, a[N], dp[N], cs=1, i;

int main() {
	scanf("%lld", &t);
	while( t-- ) {
		scanf("%lld", &n);
		for( i = 1; i <= n; ++i )
			scanf("%lld", &a[i]);
		dp[0] = 0;
		dp[1] = a[1];
		for( i = 2; i <= n; ++i ) {
			dp[i] = a[i] + dp[i-2];
			dp[i] = max( dp[i], dp[i-1] );
		}
		printf("Case %lld: %lld\n", cs++, dp[n]);
	}
	return 0;
}
