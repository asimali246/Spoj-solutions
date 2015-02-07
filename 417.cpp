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
int t, n, a, b, d, i, ct, c;
pair<int, ii> p[N] ;
priority_queue< iii > pq ;
double ans ;

bool cmp( iii a, iii b ) {
	if( a.first != b.first ) 
		return a.first < b.first ;
	if( a.second.first != b.second.first ) 
		return a.second.first > b.second.first ;
	return a.second.second < b.second.second ;
}

int main() {
	scanf("%d", &t) ;
	while( t-- ) {
		scanf("%d", &n) ;
		for( i = 1; i <= n; ++i ) {
			scanf("%d %d %d", &a, &b, &d) ;
			p[i].first = d ;
			p[i].second.first = a ;
			p[i].second.second = b ;
		}
		sort( p + 1, p + n + 1, cmp) ;
		ct = 0 ;
		ans = 0.0 ;
		pq = priority_queue<iii>() ;
		for( i = 1; i <= n; ++i ) {
			d = p[i].first ;
			a = p[i].second.first ;
			b = p[i].second.second ;
			pq.push( make_pair(a, ii(b, 0) ) ) ;
			if( ct + b > d ) {
				int need = ct + b - d ;
				iii temp = pq.top() ; pq.pop() ;
				int a = temp.first ;
				int b = temp.second.first ;
				int c = temp.second.second ;
				while( b - c <= need ) {
					need -= ( b - c ) ;
					ans += ( double ) (b - c)/a ;
					if( need == 0 ) 
						break ;
					iii temp = pq.top() ; pq.pop() ;
					a = temp.first ;
					b = temp.second.first ;
					c = temp.second.second ;
				}
				if( need != 0 ) {
					ans += ( double ) need / a ;
					c += need ; 
					pq.push( make_pair( a, ii( b, c ) ) ) ;
				}
				ct = d ;
			}
			else 
				ct += b ;
		}
		printf("%.2lf\n", ans);
	}
	return 0 ;
}
