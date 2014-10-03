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

const int N = 1e5 + 10 ;
int t, n, v, q[N], i, p = 1;
ll ans;
bool vis[N] ;

int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d", &n);
		memset( vis, 0, sizeof vis );
		p = 1;
		q[p++] = 0;
		vis[0] = 1;
		while( n-- ) {
			scanf("%d", &v);
			int s = p;
			for( i = 1; i < s ; ++i ) 
				if( !vis[ q[i] + v] ) {
					q[p++] = q[i] + v;
					vis[q[i] + v] = 1;
				}
		}
		ans = 0;
		for( i = 1; i < N; ++i )
			if(vis[i]) 
				ans += (ll)i;
		printf("%lld\n", ans);
	}
	return 0;
}
