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
int t = 10, n, i, a[N], j, I[N], R[N], pos, P[N], mx ;
vector<int> ans ;

int getPosition() {
	int l = 1, h = j, m ;
	int ans ;
	while( l <= h ) {
		m = (l + h) >> 1 ;
		if( R[m] >= a[i] )
			ans = m, h = m - 1 ;
		else
			l = m + 1 ; 
	}
	return ans ;
}

int main() {
	while( t-- ) {
		scanf("%d", &n) ;
		for( i = 1; i <= n; ++i ) 
			scanf("%d", &a[i] ) ;
		j = 0 ;
		ans.clear() ;
		for( i = 1; i <= n; ++i ) {
			if( a[i] > R[j] ) {
				++j ;
				R[j] = a[i] ;
				I[i] = j ;
			}
			else {
				pos = getPosition() ;
				R[pos] = a[i] ;
				I[i] = pos ;
			}
		}
		for( i = 1; i <= j; ++i ) 
			P[i] = -1 ;
		mx = j ;
		for( i = n; i >= 1; --i ) {
			if( I[i] == j ) {
				--j ;
				ans.push_back( a[i] ) ;
				P[j + 1] = max( P[j + 1], a[i] ) ;
			}
			else
			if( true ) {
				if( I[i] + 1 > mx ) {
					ans.push_back( a[i] ) ;
					P[I[i]] = max( P[I[i]], a[i] ) ;
				}
				else
				if( P[I[i] + 1] > a[i] ) {
					ans.push_back( a[i] ) ;
					P[I[i]] = max( P[I[i]], a[i] ) ;
				}
			}
		}
		sort( ans.begin(), ans.end() ) ;
		printf("%d\n", (int) ans.size() );
		for( i = 0; i < (int) ans.size(); ++i ) {	
			if( i > 0 ) 
				putchar(' ') ;
			printf("%d", ans[i] );
		}
		putchar('\n') ;
	}
	return 0 ;
}
