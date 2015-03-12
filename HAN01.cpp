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

typedef vector<int> vi ;
typedef pair<int, int> ii ;



int t, n, i; 
ll k ;
vector<int> ans[5] ;
ll p[70] ;

void solve(int n, int x, int y, int z, ll k) {
	if( n == 0 ) 
		return ;
	if( k == 0 ) {
		while( n ) 
			ans[x].push_back(n), --n ;
		return ;
	}
	if( p[n - 1] <= k ) {
		ans[y].push_back(n) ;
		solve(n - 1, z, y, x, k - p[n - 1] ) ;
	}
	else {
		ans[x].push_back(n) ;
		solve(n - 1, x, z, y, k ) ;
	}
}

int main() {
	scanf("%d", &t) ;
	p[0] = 1 ;
	for( i = 1; i <= 61; ++i ) 
		p[i] = p[i - 1] * 2 ;
	p[0] = 0 ;
	while( t-- ) {
		scanf("%d %lld", &n, &k) ;
		ans[1].clear() ;
		ans[2].clear() ;
		ans[3].clear() ;
		solve(n, 1, 2, 3, k) ;
		printf("1: ");
		for( i = 0; i < (int) ans[1].size(); ++i ) {
			if( i ) 
				putchar('|') ;
			printf("%d", ans[1][i]);
		}
		putchar('\n') ;
		printf("2: ");
		for( i = 0; i < (int) ans[2].size(); ++i ) {
			if( i ) 
				putchar('|') ;
			printf("%d", ans[2][i]);
		}
		putchar('\n') ;
		printf("3: ");
		for( i = 0; i < (int) ans[3].size(); ++i ) {
			if( i ) 
				putchar('|') ;
			printf("%d", ans[3][i]);
		}
		putchar('\n') ;
	}
	return 0 ;
}
