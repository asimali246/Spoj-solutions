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


const int N = 111 ;
int t, k, n, r, i, j, u, v, l, T ;
typedef pair<int, ii> iii ;
priority_queue<iii, vector<iii>, greater<iii> > pq ;
vector<iii> g[N] ;

int main() {
	scanf("%d", &t) ;
	while( t-- ) {
		scanf("%d %d %d", &k, &n, &r) ;
		for( i = 1; i <= n; ++i ) 
			g[i].clear() ;
		while( r-- ) {
			scanf("%d %d %d %d", &u, &v, &l, &T) ;
			g[u].push_back( make_pair(v, ii(l, T) ) ) ;
		}
		pq = priority_queue<iii, vector<iii>, greater<iii> >() ;
		pq.push( make_pair(0, ii(0, 1)) ) ;
		bool found = false ;
		while( !pq.empty() ) {
			iii temp = pq.top(); pq.pop() ;
			l = temp.first ;
			T = temp.second.first ;
			u = temp.second.second ;
			if( u == n )  {
				found = true ;
				break ;
			}
			for( j = 0; j < (int) g[u].size(); ++j ) {
				temp = g[u][j] ;
				v = temp.first ;
				int vl = temp.second.first ;
				int vt = temp.second.second ;
				if( T + vt <= k ) {
					pq.push( make_pair(l + vl, ii(T + vt, v))) ;
				}
			}
		}
		if( found ) 
			printf("%d\n", l);
		else
			printf("-1\n");
	}
	return 0 ;
}
