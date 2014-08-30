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
int n, m, i, t[5*N], lazy[5*N], x, y, c;

void update(int id, int l, int r, int x, int y) {
	if( l == x && r == y ) {
		t[id] = ( r - l + 1 ) - t[id];
		if( lazy[id] ) 
			lazy[id] = 0;
		else
			lazy[id] = 1;
		return;
	}
	int m = ( l + r ) >> 1;
	int lft = id << 1;
	int rgt = lft | 1;
	if( lazy[id] ) {
		t[lft] = ( m - l + 1 ) - t[lft];
		lazy[lft] = !lazy[lft];
		t[rgt] = ( r - m ) - t[rgt];
		lazy[rgt] = !lazy[rgt];
		lazy[id] = 0;
	}
	if( y <= m ) 
		update( lft, l, m, x, y);
	else
	if( x > m ) 
		update( rgt, m + 1, r, x, y);
	else
		update( lft, l, m, x, m), update( rgt, m + 1, r, m + 1, y);
	t[id] = t[lft] + t[rgt];
}
int query(int id, int l, int r, int x, int y ) {
	if( l == x && r == y )
		return t[id];
	int m = ( l + r ) >> 1;
	int lft = id << 1;
	int rgt = lft | 1;
	if( lazy[id] ) {
		t[lft] = ( m - l + 1 ) - t[lft];
		t[rgt] = ( r - m ) - t[rgt];
		lazy[lft] = !lazy[lft];
		lazy[rgt] = !lazy[rgt];
		lazy[id] = 0;
	}
	if( y <= m ) 
		return query(lft, l, m, x, y);
	else
	if( x > m )
		return query( rgt, m + 1, r, x, y);
	else
		return query( lft, l, m, x, m) + query( rgt, m + 1, r, m + 1, y);
}
int main() {
	scanf("%d %d", &n, &m);
	while( m-- ) {
		scanf("%d %d %d", &c, &x, &y);
		if( c )
			printf("%d\n", query(1, 1, n, x, y));
		else
			update(1, 1, n, x, y);
	}
	return 0;
}
