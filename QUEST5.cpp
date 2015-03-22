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



const int N = 1e5 + 100 ;
int t, n, i, ans, E;
ii p[N] ;

inline void Move() {
	++i ;
	while( i <= n && p[i].first <= E ) {
		++i ;
	}
}
bool cmp( ii a, ii b ) {
	if( a.second != b.second ) 
		return a.second < b.second ;
	return a.first < b.first ;
}
int main() {
	scanf("%d", &t) ;
	while( t-- ) {
		scanf("%d", &n) ;
		for( i = 1; i <= n; ++i ) {
			scanf("%d %d", &p[i].first, &p[i].second ) ;
		}
		sort( p + 1, p + n + 1, cmp) ;
		ans = 0 ;
		for( i = 1; i <= n; ) {
			E = p[i].second ;
			++ans ;
			Move() ;
		}
		printf("%d\n", ans);
	}
	return 0 ;
}
