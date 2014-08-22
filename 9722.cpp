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

const int N = 1<<17;
int t, n, a[N], i, j, b[N], s;
ll ans;

void Merge(int l, int m, int r) {
	i = l, j = m + 1;
	s = 1;
	while( i <= m && j <= r ) {
		if( a[i] <= a[j])
			b[s++] = a[i++];
		else
			b[s++] = a[j++], ans += (m - i + 1);
	}
	while( i <= m )
		b[s++] = a[i++];
	while( j <= r )
		b[s++] = a[j++];
	s = 1;
	for( i = l; i <= r; ++i )
		a[i] = b[s++];
}

void Solve(int l, int r) {
	if( l < r ) {
		int m = ( l + r ) >> 1;
		Solve( l, m);
		Solve( m + 1, r);
		Merge( l, m, r);
	}
}

int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d", &n);
		for( i = 1; i <= n; ++i )
			scanf("%d", &a[i]);
		ans = 0;
		Solve(1, n);
		printf("%lld\n", ans);
	}
	return 0;
}
