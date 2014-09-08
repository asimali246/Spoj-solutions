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
int t, n, a[N], vis[N], i, ans, v, j;

int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d", &n);
		for( i = 1;i <= n; ++i )
			scanf("%d", &a[i]), vis[i] = 1;
		ans = 0;
		sort( a + 1, a + n + 1);
		for( i = 1;i <= n; ++i ) {
			v = a[i] * 2;
			if( !vis[i] )
				continue;
			for( j = i + 1; j <= n; ++j ) {
				if( a[j] == v && vis[j] ) {
					++ans;
					vis[j] = 0;
					break; 
				} 
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
