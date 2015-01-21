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

const int N = 11 ;
int t, n, p, i, j, ans, a[N], v, cs = 1, s[N];

int main() {
	scanf("%d", &t) ;
	while( t-- ) {
		scanf("%d %d", &n, &p) ;
		ans = 7 ;
		memset( s, 0, sizeof s ) ;
		for( i = 1; i <= n; ++i ) {
			a[i] = 0 ;
			for( j = 1; j <= p; ++j ) {
				scanf("%d", &v ) ;
				if( v ) 
					a[i] |= ( 1 << (j - 1) ) , s[j] = 1 ;
			}
		}
		for( i = 1; i <= p; ++i ) 
			if( !s[i] )
				ans = 3 ;
		for( i = 1; i <= n; ++i ) 
			if( a[i] == 0 )
				ans = ans & 5 ;
		for( i = 1; i <= n; ++i )
			if( a[i] == ( ( 1 << p ) - 1 ) )
				ans = ans & 6 ;
		printf("Case %d: %d\n", cs++, ans);
	}
	return 0 ;
}
