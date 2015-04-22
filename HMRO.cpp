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

const int N = 1e5 + 10 ;
int t, n, P[N], i, c, x, y, num, j;
ll q ;
map<ll, string> Pesel ;
map<string, int> mp ;
map<int, string> rev ;
char s[5] ;
bool flag = false ;

int findSet(int x) {
	if( x == P[x] ) 
		return x ;
	else
		return P[x] = findSet(P[x]) ;
}
bool sameSet(int x, int y) {
	return findSet(x) == findSet(y) ;
}
void Union(int x, int Y) {
	if( !sameSet(x, y) ) {
		P[findSet(x)] = P[findSet(y)] ;
	}
}
int main() {
	scanf("%d", &t) ;
	while( t-- ) {
		scanf("%d", &n) ;
		num = 1 ;
		mp.clear() ;
		rev.clear() ;
		Pesel.clear() ;
		for( i = 1; i <= n; ++i ) {
			scanf("%lld %s", &q, s) ;
			Pesel[q] = s ;
			if( mp.count(s) == 0 )
				mp[s] = num, rev[num] = s, ++num ;
		}
		scanf("%d", &c) ;
		--num ;
		for( i = 1; i <= num; ++i ) 
			P[i] = i ;
		while( c-- ) {
			scanf("%s", s) ;
			x = mp[s] ;
			scanf("%s", s) ;
			y = mp[s] ;
			Union(x, y) ;
		}
		scanf("%d", &c) ;
		if( flag ) 
			putchar('\n') ;
		flag = true ;
		while( c-- ) {
			scanf("%lld", &q) ;
			x = findSet(mp[Pesel[q]]) ;
			printf("%lld %s\n", q, rev[x].c_str() ) ;
		}
	}
	return 0 ;
}
