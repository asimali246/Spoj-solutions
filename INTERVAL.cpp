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


template < typename X > X gcd( X a, X b ) { if( !b ) return a ; else return gcd(b, a%b) ; }

typedef pair<int, int> ii ; 

const int N = 50000 + 1000 ;
int t, n, a, b, c, i, ans, T[N * 5], p, q, L[5 * N] ;
pair<ii, int> P[N] ;

bool cmp(pair<ii, int> a, pair<ii, int> b ) {
	if( a.first.second != b.first.second ) 
		return a.first.second < b.first.second ;
	if( a.second != b.second ) 
		return a.second > b.second ;
	return a.first.first < b.first.first ;
}

void update(int id, int l, int r, int a, int b) {
	if( l == a && r == b ) {
		T[id] = b - a + 1 ;
		L[id] = 1 ;
		return ;
	}
	int lft, rgt, m;
	lft = id << 1 ;
	rgt = lft | 1 ;
	m = (l + r) >> 1 ;
	if( b <= m ) 
		update(lft, l, m, a, b) ;
	else
	if( a > m ) 
		update(rgt, m + 1, r, a, b ) ;
	else
		update(lft, l, m, a, m), update(rgt, m + 1, r, m + 1, b) ;
	T[id] = T[lft] + T[rgt] ;
}

int query(int id, int l, int r, int a, int b) {
	if( l == a && r == b )
		return T[id] ;
	int lft, rgt, m ;
	m = (l + r) >> 1 ;
	lft = id << 1 ;
	rgt = lft | 1 ;
	if( L[id] ) {
		L[lft] = 1 ;
		L[rgt] = 1 ;
		L[id] = 0 ;
		T[lft] = m - l + 1 ;
		T[rgt] = r - m ; 
	}
	if( b <= m ) 
		return query(lft, l, m, a, b) ;
	else
	if( a > m ) 
		return query(rgt, m + 1, r, a, b) ;
	else
		return query(lft, l, m, a, m) + query(rgt, m + 1, r, m + 1, b) ;
}

int main() {
	scanf("%d", &t) ;
	while( t-- ) {
		scanf("%d", &n) ;
		for(i = 1; i <= n; ++i ) {
			scanf("%d %d %d", &a, &b, &c) ;
			P[i].first.first = a ;
			P[i].first.second = b ;
			P[i].second = c ;
		}
		sort( P + 1, P + n + 1, cmp ) ;
		ans = 0 ;
		memset(T, 0, sizeof T) ;
		memset(L, 0, sizeof L) ;
		for( i = 1; i <= n; ++i ) {
			pair<ii, int> temp = P[i] ;
			a = temp.first.first ;
			b = temp.first.second ;
			c = temp.second ;
			p = query(1, 0, N, a, b) ;
			if( p < c ) {
				int r = c - p ;
				int l, h, m ;
				l = 0, h = b ;
				while( l <= h ) {
					m = (l + h) >> 1 ;
					p = query(1, 0, N, m, b) ;
					if( b - m + 1 - p == r ) {
						break ;
					}
					else
					if( b - m + 1 - p > r ) 
						l = m + 1 ;
					else
						h = m - 1 ;
				}
				update(1, 0, N, m, b) ;
				ans += r ;
			}
		}
		printf("%d\n", ans) ;
	}
	return 0 ;
}
