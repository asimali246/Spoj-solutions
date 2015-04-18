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


const int N = 3030 ;
int t, s, w, b, a[N], i, c, j;
vector<int> v, ans ;
int lip, uip ;

int main() {
	scanf("%d", &t) ;
	while( t-- ) {
		scanf("%d %d %d", &s, &w, &b) ;
		v.clear() ;
		for( i = 1; i <= b; ++i ) 
			scanf("%d", &a[i] ), v.push_back( a[i] ) ;
		sort( v.begin(), v.end() ) ;
		c = -1 ;
		lip = b / s ;
		uip = b - (lip * s) ;
		i = 0 ;
		while( true ) {
			++c ;
			if( c == w ) 
				break ;
			i += lip ;
			if( uip ) {
				--uip ;
				++i ;
			}
		}
		ans.clear() ;
		if( uip ) 
			++lip ;
		for( ; i < b; ++i ) {
			ans.push_back( v[i] ) ;
			--lip ;
			if( lip == 0 ) 
				break ;
		}
		for( i = 1; i <= b; ++i ) {
			bool flag = false ;
			for( j = 0; j < (int) ans.size(); ++j ) {
				if( ans[j] == a[i] ) {
					flag = true ;
					break ;
				}
			}
			if( flag ) 
				break ;
		}
		printf("%d\n", a[i] );
	}
	return 0 ;
}
