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



const int N = 5555 ;
int t = 10, n, p, k, a, b, i, mx, mn, cnt;
map<int, ii> mp ;

int main() {
	while( t-- ) {
		scanf("%d %d", &p, &k) ;
		scanf("%d", &n) ;
		mp.clear() ;
		mp[p] = ii(0, 0) ;
		for( i = 1; i <= n; ++i) {
			scanf("%d %d", &a, &b) ;
			if( p > b || k < a ) 
				continue ;
			mx = max(a, p) ;
			if( mp.count( mx ) == 0 )
				mp[mx] = ii(0, 0) ;
			mp[mx] = ii( mp[mx].first + 1, mp[mx].second ) ;
			if( b >= k ) 
				continue ;
			if( mp.count(b) == 0 )
				mp[b] = ii(0, 0) ;
			mp[b] = ii( mp[b].first, mp[b].second - 1 ) ;
		}
		map<int, ii>::iterator it = mp.begin() ;
		cnt = 0 ;
		mx = -INF ;
		mn = INF ;
		while( it != mp.end() ) {
			cnt += it -> second.first ;
			mx = max( mx, cnt ) ;
			cnt += it -> second.second ;
			mn = min( mn, cnt ) ;
			++it ;
		}
		if( mx == -INF ) 
			mx = 0 ;
		if( mn == INF ) 
			mn = 0 ;
		printf("%d %d\n", mn, mx);
	}
	return 0 ;
}
