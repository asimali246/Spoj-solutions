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

int n, m, i, k, v, u, g[111][111], deg[111], vis[111];
vi ans;

int main() {
	scanf("%d %d", &n, &m);
	while( m-- ) {
		scanf("%d %d", &v, &k);
		while( k-- ) 
			scanf("%d", &u), g[u][v] = 1, deg[v]++;
	}
	ans.clear();
	while( (int)ans.size() != n ) {
		for( i = 1; i <= n; ++i )
			if( !deg[i] && !vis[i] ) {
				ans.push_back(i);
				vis[i] = 1;
				for( v = 1; v <= n; ++v ){
					if( g[i][v] )
						g[i][v] = 0, --deg[v];
				}
				break;
			}
	}
	for( i = 0; i < (int) ans.size(); ++i ) {
		if( i > 0 )
			putchar(' ');
		printf("%d", ans[i]);
	}
	putchar('\n');
	return 0;
}
