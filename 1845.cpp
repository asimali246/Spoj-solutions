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

const ll N = 111;
ll i, j, k, n, m, e, t, a, b, c, g[N][N], ans;

int main() {
	scanf("%lld %lld %lld", &n, &e, &t);
	scanf("%lld", &m);
	for( i = 1; i <= n; ++i )
		for( j = 1 ; j <= n; ++j )
			g[i][j] = (i == j) ? 0 : (ll)INF/100 * INF;
	while( m-- ) {
		scanf("%lld %lld %lld", &a, &b, &c);
		g[a][b] = c;
	}
	for( k = 1; k <= n; ++k )
		for( i = 1; i <= n; ++i )
			for( j = 1; j <= n; ++j )
				g[i][j] = min( g[i][j], g[i][k]+g[k][j]);
	for( i = 1; i <= n; ++i )
		if( g[i][e] <= t )
			++ans;
	printf("%lld\n", ans);
	return 0;
}
