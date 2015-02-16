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



const int N = 1e4 + 10 ;
struct Line {
	double a, b, c ;
	double x1, y1, x2, y2 ;
};
int i, n, ans;
double X1, Y1, X2, Y2, m;
Line eq[N] ;
typedef pair<double, double> dd ;
priority_queue<pair<dd, int>, vector<pair<dd, int> >, greater<pair<dd, int> > > pq ;


bool cmp( Line x, Line y ) {
	if( x.a < y.a ) 
		return true ;
	if( y.a < x.a )
		return false ;
	if( x.c < y.c ) 
		return true ;
	if( y.c < x.c )
		return false ;
	return false ;
}

int main() {
	while( 1 ) {
		scanf("%d", &n) ;
		if( !n ) 
			break ;

		for( i = 1; i <= n; ++i ) {
			scanf("%lf %lf %lf %lf", &X1, &Y1, &X2, &Y2 ) ;
			if( X1 > X2 ) {
				swap( X1, X2 ) ;
				swap( Y1, Y2 ) ;
			}
			else
			if( X1 == X2 && Y1 > Y2 ) {
				swap ( X1, X2 ) ;
				swap( Y1, Y2 ) ;
			}
			eq[i].x1 = X1 ;
			eq[i].x2 = X2 ;
			eq[i].y1 = Y1 ;
			eq[i].y2 = Y2 ;
			if( abs(X2 - X1) < EPS ) {
				eq[i].b = 0.0 ;
				eq[i].a = 1 ;
				eq[i].c = -X1 ;
			}
			else {
				m = ( Y2 - Y1 ) / ( X2 - X1 ) ;
				eq[i].a = m ;
				eq[i].b = -1.0 ;
				eq[i].c = Y1 - m * X1 ;
			}
		}
		sort( eq + 1, eq + n + 1, cmp ) ;

		pq = priority_queue<pair<dd, int>, vector<pair<dd, int> >, greater<pair<dd, int> > >() ;
		ans = 0 ;
		pq.push( make_pair(make_pair( eq[1].x1, eq[1].y1 ), 1) ) ;
		pq.push( make_pair(make_pair( eq[1].x2, eq[1].y2 ), 2) ) ;
		for( i = 2; i <= n; ++i ) {
			if( abs( eq[i].a - eq[i - 1].a ) < EPS && abs( eq[i].c - eq[i - 1].c ) < EPS ) {
				pq.push( make_pair(make_pair( eq[i].x1, eq[i].y1 ), 1) ) ;
				pq.push( make_pair(make_pair( eq[i].x2, eq[i].y2 ), 2) ) ;
			} 
			else {
				int open = 0 ;
				while( !pq.empty() ) {
					pair<dd, int> temp = pq.top() ; pq.pop() ;
					if( temp.second == 2 ) {
						open-- ;
					}
					else {
						if( !open ) {
							++ans ;
						}
						open++ ;
					}
				}
				pq.push( make_pair(make_pair( eq[i].x1, eq[i].y1 ), 1) ) ;
				pq.push( make_pair(make_pair( eq[i].x2, eq[i].y2 ), 2) ) ;
			}
		}
		int open = 0 ;
		while( !pq.empty() ) {
			pair<dd, int> temp = pq.top() ; pq.pop() ;
			if( temp.second == 2 ) {
				open-- ;
			}
			else {
				if( !open ) {
					++ans ;
				}
				open++ ;
			}
		}		
		printf( "%d\n", ans ) ;
	}
	return 0 ;
}
