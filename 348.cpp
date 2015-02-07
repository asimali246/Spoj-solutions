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
int t, n, i, ans, f, d, c, td;
ii p[N] ;
bool flag ;
priority_queue<int> pq ;

int main() {
	scanf("%d", &t) ;
	while( t-- ) {
		scanf("%d", &n) ;
		for( i = 1; i <= n; ++i ) 
			scanf("%d %d", &p[i].first, &p[i].second ) ;
		scanf("%d %d", &d, &f) ;
		sort( p + 1, p + n + 1 ) ;
		reverse( p + 1, p + n + 1 ) ;
		for( i = 1; i <= n; ++i ) {
			p[i].first = d - p[i].first ;
		}
		ans = 0 ;
		c = 0 ;
		flag = true ;
		pq = priority_queue<int>() ;
		for( i = 1; i <= n; ++i ) {
			td = p[i].first - c ;
			if( f < td ) {
				if( pq.empty() ) {
					flag = false ;
					break ;
				}
				f += pq.top() ;
				pq.pop() ;
				--i ;
				++ans ;
			} 
			else {
				f -= td ;
				pq.push( p[i].second ) ;
				c = p[i].first ;
			}
		}
		td = d - c ;
		while( f < td ) {
			if( pq.empty() ) {
				flag = false ;
				break ;
			}
			f += pq.top() ;
			pq.pop() ;
			++ans ;
		}
		if( !flag ) {
			printf("-1\n");
			continue ;
		}
		printf("%d\n", ans ) ;
	}
	return 0 ;
}
