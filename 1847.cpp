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

const int N = 1e5 + 10;
struct Node {
	int a[6];
}ans[N];

int x, k, i, vis[N], v, p = 1, j;

int main() {
	scanf("%d %d", &x, &k);
	while( k-- ) {
		scanf("%d", &v);
		if( p == 1 ) 
			for( i = v; i <= x; i += v )
				vis[i] = 1, ans[i].a[p] = ans[i-v].a[p] + 1;
		else {
			for( i = 1; i <= x; ++i ) {
				if( vis[i] && ans[i].a[p] < ans[i].a[p - 1] && i + v <= x && !vis[i + v]) {
					ans[i + v].a[p - 1] = ans[i].a[p - 1];
					ans[i + v].a[p] = ans[i].a[p] + 1;
					vis[i + v] = 1;
				} 
			}
		}
		++p;
	}
	if( vis[x] )
		puts("YES");
	else
		puts("NO");
	return 0;
}
