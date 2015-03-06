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



const int N = 150000 + 10 ;
int t, nm, nk, a[2222], b[2222], p[N], c[N], i, j, q, cnt;

int main() {
	scanf("%d", &t) ;
	while( t-- ) {
		scanf("%d %d %d", &q, &nm, &nk) ;
		for( i = 1; i <= nm; ++i ) 
			scanf("%d", &a[i] ) ;
		for( i = 1; i <= nk; ++i ) 
			scanf("%d", &b[i] ) ;
		for( i = 1; i <= q; ++i ) 
			p[i] = 0 ;
		for( i = 1; i <= nm; ++i ) {
			cnt = a[i] - 1 ;
			for( j = 2; j <= q; ++j ) {
				c[j] = -INF ;
				if( cnt == 0 ) {
					if( c[j - 1] >= p[j] ) 
						c[j] = c[j - 1] ;
					else {
						c[j] = p[j] ;
						cnt = a[i] ;
					}
				}
				else {
					if( cnt != a[i] ) {
						if( c[j - 1] + 1 >= p[j] ) 
							c[j] = c[j - 1] + 1, cnt-- ;
						else 
							c[j] = p[j], cnt = a[i] ;
					}
					else {
						if( c[j - 1] >= p[j] ) 
							c[j] = c[j - 1], cnt-- ;
						else
							c[j] = p[j], cnt = a[i] ;
					}
				}
				if( j >= a[i] ) {
					if( c[j] < p[j - a[i]] + a[i] ) 
						c[j] = p[j - a[i]] + a[i], cnt = 0 ;
				}
			}
			for( j = 1; j <= q; ++j ) 
				p[j] = c[j] ;
		}
		for( i = 1; i <= nk; ++i ) {
			cnt = b[i] - 1 ;
			for( j = 2; j <= q; ++j ) {
				c[j] = -INF ;
				if( cnt == 0 ) {
					if( c[j - 1] >= p[j] ) 
						c[j] = c[j - 1] ;
					else {
						c[j] = p[j] ;
						cnt = b[i] ;
					}
				}
				else {
					if( cnt != b[i] ) {
						if( c[j - 1] + 1 >= p[j] ) 
							c[j] = c[j - 1] + 1, cnt-- ;
						else 
							c[j] = p[j], cnt = b[i] ;
					}
					else {
						if( c[j - 1] >= p[j] ) 
							c[j] = c[j - 1], cnt-- ;
						else
							c[j] = p[j], cnt = b[i] ;
					}
				}
				if( j >= b[i] ) {
					if( c[j] < p[j - b[i] ] + b[i] - 1 ) 
						c[j] = p[j - b[i] ] + b[i] - 1, cnt = 0 ;
				}
			}
			for( j = 1; j <= q; ++j )
				p[j] = c[j] ;
		}
		printf("%d\n", c[q]);
	}
	return 0 ;
}
