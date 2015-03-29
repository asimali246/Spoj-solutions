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
typedef pair<int, ii> iii ;
vector<iii> v ;
vector<iii> temp ;
int t, i, n, x, y, l, k, T;
double C ;

bool cmp( iii a, iii b ) {
	if( a.second.second != b.second.second ) 
		return a.second.second < b.second.second ;
	return a.second.first < b.second.first ;
}

bool rmv( iii a, iii b ) {
	return (a.second.first == b.second.first) && (a.second.second == b.second.second) ;
}

int ccw( ii a, ii b, ii c ) {
	return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first) ;
}
double Dist(ii a, ii b) {
	return hypot( (double) (a.first - b.first), (double) (a.second - b.second) ) ;
}
int main() {
	scanf("%d", &t) ;
	while( t-- ) {
		scanf("%d", &n) ;
		v.clear() ;
		for( i = 1; i <= n; ++i ) {
			scanf("%d %d", &x, &y) ;
			iii p ;
			p.first = i ;
			p.second.first = x ;
			p.second.second = y ;
			v.push_back( p ) ;
		}
		sort( v.begin(), v.end(), cmp ) ;
		v.resize( unique( v.begin(), v.end(), rmv ) - v.begin() ) ;
		temp.clear() ;
		l = (int) v.size() ;
		k = 0 ;
		for( i = 0; i < l; ++i ) {
			iii p = v[i] ;
			while( k >= 2 && ccw(temp[k - 2].second, temp[k - 1].second, p.second ) <= 0 )
				--k, temp.pop_back() ;
			temp.push_back( p ) ; 
			++k ;
		}
		T = k + 1 ;
		for( i = l - 2 ; i >= 0 ; --i ) {
			iii p = v[i] ;
			while( k >= T && ccw( temp[k - 2].second, temp[k - 1].second, p.second ) <= 0 )
				--k, temp.pop_back() ;
			temp.push_back( p ) ;
			++k ;
		}
		C = 0.0 ;
		for( i = 1; i < (int) temp.size(); ++i ) {
			C += Dist( temp[i].second, temp[i - 1].second ) ;
		}
		printf("%.2lf\n", C );
		if( C == 0.0 )
			printf("1\n");
		bool flag = false ;
		for( i = 0; i < (int) temp.size() - 1; ++i ) {
			if( flag ) 
				putchar(' ') ;
			flag = true ;
			printf("%d", temp[i].first );
		} 
		putchar('\n') ;
		putchar('\n') ;
	}
	return 0 ;
}

