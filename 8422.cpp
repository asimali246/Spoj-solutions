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

const int N = 111;
int t, m, n, a[N][N], b[N][N], c[N][N], i, j;
ll ans, mx;

int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d %d", &m, &n);
		for( i = 1; i <= m; ++i )
			for( j = 1; j <= n; ++j )
				scanf("%d", &a[i][j]);
		for( i = 1; i <= m; ++i )
			for( j = 1; j <= n; ++j )
				scanf("%d", &b[i][j]);
		for( i = 1; i <= m; ++i )
			for( j = 1; j <= n; ++j )
				scanf("%d", &c[i][j]);
		ans = 0;
		for( i = 1; i <= m; ++i ) {
			mx = -INF;
			for( j = 1; j <= n; ++j )
				mx = max( mx, (ll)min(a[i][j], b[i][j]) * (ll)c[i][j] );
			ans += mx;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
