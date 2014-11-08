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
 
typedef vector<int> vi;
typedef pair<int, int> ii;


struct Trie {
	int L, R ;
	Trie *Next[2] ;
} ;

const int N = 1e5 + 10 ;
int t, n, k, a[N], i, X ;
ll ans ;

Trie *root, *trav;

Trie* New() {
	Trie *tmp ;
	tmp = new Trie ;
	tmp -> Next[0] = tmp -> Next[1] = NULL ;
	tmp -> L = tmp -> R = 0 ;
	return tmp ;
}

void Insert(Trie *trav, int v, int j) {
	if( j == 0 ) {
		if( v & 1 ) {
			if( !trav -> Next[1] ) {
				trav -> Next[1] = New() ;
				trav -> R = 0 ;
			}
			++trav -> R ;
			return;
		}
		else {
			if( !trav -> Next[0] ) {
				trav -> Next[0] = New() ;
				trav -> L = 0 ;
			}
			++trav -> L ;
			return;
		}
	}
	if( v & ( 1 << j ) ) {
		if( !trav -> Next[1] ) {
			trav -> Next[1] = New() ;
		}
		Insert( trav -> Next[1], v, j - 1 ) ;
		trav -> R = ( trav -> Next[1] -> L ) + ( trav -> Next[1] -> R ) ;
	}
	else {
		if( !trav -> Next[0] ) {
			trav -> Next[0] = New() ;
		}
		Insert( trav -> Next[0], v, j - 1 ) ;
		trav -> L = ( trav -> Next[0] -> L ) + ( trav -> Next[0] -> R ) ;
	}
}

ll getNum(int v) {
	ll ans = 0 ;
	trav = root ;
	int j = 17 ;
	while( true ) {
		if( k & ( 1 << j ) ) {
			if( v & ( 1 << j ) ) {
				ans += trav -> R ;
				if( !trav -> Next[0] )
					break ;
				trav = trav -> Next[0] ;
			}
			else {
				ans += trav -> L ;
				if( !trav -> Next[1] ) 
					break ;
				trav = trav -> Next[1] ;
			}
		}
		else {
			if( v & ( 1 << j ) ) {
				if( !trav -> Next[1] )
					break ;
				trav = trav -> Next[1] ;
			}
			else {
				if( !trav -> Next[0] ) 
					break ;
				trav = trav -> Next[0] ;
			}
		}
		--j ;
		if( j < 0 ) {
			break ;
		}
	}
	return ans ;
}

int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d %d", &n, &k ) ;
		for( i = 1; i <= n; ++i ) {
			scanf("%d", &a[i] ) ;
		}
		ans = X = 0 ;
		root = New() ;
		Insert(root, 0, 17) ;
		for( i = 1; i <= n; ++i ) {
			X ^= a[i] ;
			ans += getNum(X) ;
			Insert(root, X, 17) ;
		}
		printf("%lld\n", ans);
	}
	return 0 ;
}
