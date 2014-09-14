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

struct Node {
	int a, b, c;
}t[4*N];

int n, q, x, y, c, lazy[4*N], tmp;

inline void combine(Node a, Node b, Node &c) {
	c.a = a.a + b.a;
	c.b = a.b + b.b;
	c.c = a.c + b.c;
}
void build(int id, int l, int r) {
	if(l == r) {
		t[id].a = 1;
		t[id].b = t[id].c = 0;
		return;
	}
	int m = (l + r) >> 1;
	int lft, rgt;
	lft = id << 1;
	rgt = lft | 1;
	build(lft, l, m);
	build(rgt, m + 1, r);
	combine(t[lft], t[rgt], t[id]);
}

inline void operation(Node &p, int c) {
	if( c == 0 )
		return;
	if(c == 1) {
		tmp = p.c;
		p.c = p.b;
		p.b = p.a;
		p.a = tmp;
	}
	if( c == 2 ) {
		tmp = p.c;
		p.c = p.a;
		p.a = p.b;
		p.b = tmp;
	}
}
void update(int id, int l, int r, int x, int y) {
	if( l == x && r == y ) {
		operation(t[id], 1);
		lazy[id] = (lazy[id] + 1) % 3;
		return;
	}
	int m, lft, rgt;
	m = (l + r) >> 1;
	lft = id << 1;
	rgt = lft | 1;
	operation(t[lft], lazy[id]);
	operation(t[rgt], lazy[id]);
	lazy[lft] = (lazy[id] + lazy[lft]) % 3;
	lazy[rgt] = (lazy[id] + lazy[rgt]) % 3;
	lazy[id] = 0;
	if( y <= m )
		update(lft, l, m, x, y);
	else
	if( x > m )
		update(rgt, m + 1, r, x, y);
	else
		update(lft, l, m, x, m), update(rgt, m + 1, r, m + 1, y);
	combine(t[lft], t[rgt], t[id]);
}

Node query(int id, int l, int r, int x, int y) {
	if( l == x && r == y )
		return t[id];
	int m, lft, rgt;
	m = (l + r) >> 1;
	lft = id << 1;
	rgt = lft | 1;
	operation(t[lft], lazy[id]);
	operation(t[rgt], lazy[id]);
	lazy[lft] = (lazy[id] + lazy[lft]) % 3;
	lazy[rgt] = (lazy[id] + lazy[rgt]) % 3;
	lazy[id] = 0;
	if( y <= m )
		return query(lft, l, m, x, y);
	else
	if( x > m )
		return query(rgt, m + 1, r, x, y);
	else {
		Node a = query(lft, l, m, x, m);
		Node b = query(rgt, m + 1, r, m + 1, y);
		Node c;
		combine(a, b, c);
		return c;
	}
}

int main() {
	scanf("%d %d", &n, &q);
	build(1, 1, n);
	while(q--) {
		scanf("%d %d %d", &c, &x, &y);
		++x, ++y;
		if(c)
			printf("%d\n", query(1, 1, n, x, y).a);
		else
			update(1, 1, n, x, y);
	}
	return 0;
}
