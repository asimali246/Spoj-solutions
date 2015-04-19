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


const int N = 400100 ;
const int CN = 555 ;
int t, n, r, i, j, a[CN][CN], mx[N], my[N], rmx[CN], rmy[CN], num, x, y, k, h[CN], ans, tmx, ind ;
pair<ii, ii> R[CN] ;
vector<int> v ;
stack<int> st ;

void solve() {
	st = stack<int>() ;
	tmx = 0 ;
	int i ;
	for( i = 1; i <= x; ++i ) {
		if( st.empty() ) {
			st.push( i ) ;
		} else {
			ind = st.top() ;
			if( h[i] >= h[ind] ) {
				st.push(i) ;
			} else {
				while( h[ind] > h[i] ) {
					st.pop() ;
					tmx = max( h[ind] * ( rmx[i - 1] - rmx[ind - 1] ), tmx ) ;
					if( st.empty() ) 
						break ;
					ind = st.top() ;
				}
			}
		}
	}
	while( true ) {
		if( st.empty() ) 
			break ;
		ind = st.top() ;
		st.pop() ;
		tmx = max( tmx, h[ind] * (rmx[x] - rmx[ind - 1]) ) ;
	}
}

int main() {
	scanf("%d", &t) ;
	while( t-- ) {
		scanf("%d %d", &n, &r) ;
		for( i = 1; i <= r; ++i ) {
			scanf("%d %d %d %d", &R[i].first.first, &R[i].first.second, &R[i].second.first, &R[i].second.second ) ;
		}	
		for( i = 0; i < N; ++i ) {
			mx[i] = my[i] = -1 ;
		}
		num = 0 ;
		mx[0] = num++ ;		
		v.clear() ;
		for( i = 1; i <= r; ++i ) {
			v.push_back( R[i].first.first ) ;
			v.push_back( R[i].first.second ) ;
		}
		sort( v.begin(), v.end() ) ;
		for( i = 0; i < (int) v.size(); ++i ) {
			if( mx[v[i]] == -1 ) {
				mx[v[i]] = num++ ;
				rmx[num - 1] = v[i] ;
			}
		}
		if(mx[n] == -1) {
			mx[n] = num++ ;
			rmx[num - 1] = n ;
		}
		--num ;
		x = num ;
		num = 0 ;
		my[0] = num++ ;
		v.clear() ;
		for( i = 1; i <= r; ++i ) {
			v.push_back( R[i].second.first ) ;
			v.push_back( R[i].second.second ) ;
		}
		sort( v.begin(), v.end() ) ;
		for( i = 0; i < (int) v.size(); ++i ) {
			if( my[v[i]] == -1 ) {
				my[v[i]] = num++ ;
				rmy[num - 1] = v[i] ;
			}
		}
		if( my[n] == -1 ) {
			my[n] = num++ ;
			rmy[num - 1] = n ;
		}
		--num ;
		y = num ;
		for( i = 1; i <= y; ++i ) 
			for( j = 1; j <= x; ++j ) 
				a[i][j] = 1 ;
		for( i = 1; i <= r; ++i ) {
			for( j = my[R[i].second.first] + 1; j <= my[R[i].second.second]; ++j ) 
				for( k = mx[R[i].first.first] + 1; k <= mx[R[i].first.second]; ++k )
					a[y - j + 1][k] = 0 ;
		}
		ans = 0 ;
		for( i = 1; i <= x; ++i ) 
			h[i] = 0; 
		for( i = 1; i <= y; ++i ) {
			for( j = 1; j <= x; ++j ) {
				if( a[i][j] ) 
					h[j] += rmy[y - i + 1] - rmy[y - i] ;
				else
					h[j] = 0 ;
			}
			solve() ;
			ans = max( ans, tmx ) ;
		}
		printf("%d\n", ans ) ;
	}
	return 0 ;
}
