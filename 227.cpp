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

const int N = 201000;
int T, n, a[N], i, ans[N], t[4*N], p, s;

void build(int id, int l, int r) {
	if(l == r) {
		t[id] = 1;
		return;
	}
	int m = (l + r) >> 1;
	build(id << 1, l, m );
	build( ( id << 1 ) | 1, m + 1, r ) ;
	t[id] = r - l + 1;
}
int query(int id, int l, int r, int p) {
	if( l == r ) {
		t[id]--;
		return l;
	}
	int m , lft, rgt;
	m = ( l + r ) >> 1;
	lft = id << 1, rgt = lft | 1;
	t[id]--;
	if( p <= t[lft] )
		return query(lft, l, m, p);
	else
		return query(rgt, m + 1, r, p - t[lft]);
}
int main() {
	scanf("%d", &T);
	while( T-- ) {
		scanf("%d", &n);
		for( i = 1; i <= n; ++i )
			scanf("%d", &a[i]);
		build(1, 1, n);
		for( i = n; i >= 1; --i ) {
			s = i - a[i];
			ans[i] = query(1, 1, n, s);
		}
		printf("%d", ans[1]);
		for( i = 2; i <= n; ++i )
			printf(" %d", ans[i]);
		putchar('\n');
	}
	return 0;
}
