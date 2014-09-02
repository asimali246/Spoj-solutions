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

const int N = 1 << 17;
int n, q, x, y, i, a[N];
struct Node {
	int lf, rf, lv, rv, bf;
}t[4*N];

void build(int id, int l, int r) {
	if( l == r ) {
		t[id].lf = t[id].rf = t[id].bf = 1;
		t[id].lv = t[id].rv = a[l];
		return;
	}
	int m, lft, rgt, v;
	m = ( l + r ) >> 1;
	lft = id << 1, rgt = lft | 1;
	build( lft, l, m );
	build( rgt, m + 1, r );
	if( t[lft].rv == t[rgt].lv ) 
		v = t[lft].rf + t[rgt].lf;
	else
		v = -INF;
	t[id].bf = max( max( t[lft].bf, t[rgt].bf ) , v );
	if( t[lft].lv == t[rgt].lv ) 
		v = t[lft].lf + t[rgt].lf;
	else
		v = t[lft].lf;
	t[id].lf = v, t[id].lv = t[lft].lv;
	if( t[rgt].rv == t[lft].rv ) 
		v = t[rgt].rf + t[lft].rf;
	else
		v = t[rgt].rf;
	t[id].rf = v, t[id].rv = t[rgt].rv;
}
Node query(int id, int l, int r, int x, int y) {
	if( l == x && r == y ) 
		return t[id];
	int m, lft, rgt, v;
	m = ( l + r ) >> 1;
	lft = id << 1, rgt = lft | 1;
	if( y <= m ) 
		return query( lft, l, m, x, y);
	else
	if( x > m ) 
		return query( rgt, m + 1, r, x, y);
	else {
		Node a = query( lft, l, m, x, m);
		Node b = query( rgt, m + 1, r, m + 1, y);
		Node ans;
		if( a.rv == b.lv ) 
			v = a.rf + b.lf;
		else
			v = -INF;
		ans.bf = max( max( a.bf, b.bf ) , v );
		if( a.lv == b.lv ) 
			v = a.lf + b.lf;
		else
			v = a.lf;
		ans.lf = v, ans.lv = a.lv;
		if( b.rv == a.rv ) 
			v = b.rf + a.rf;
		else
			v = b.rf;
		ans.rf = v, ans.rv = b.rv;
		return ans;
	}
}
int main() {
	while( 1 ) {
		scanf("%d", &n);
		if( !n )
			break;
		scanf("%d", &q);
		for( i = 1; i <= n; ++i )
			scanf("%d", &a[i]);
		build( 1, 1, n );
		while( q-- ) {
			scanf("%d %d", &x, &y);
			printf("%d\n", query( 1, 1, n, x, y).bf);
		}
	}
	return 0;
}
