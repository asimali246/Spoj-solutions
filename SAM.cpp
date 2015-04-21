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

const int N = 5 * 1e5 + 10 ;
int t, n, k, p, i, ans, c, a[N], V[N] ;
priority_queue<ii> pq ;
list<int> Pos[N] ;

int main() {
	scanf("%d", &t) ;
	while( t-- ) {
		scanf("%d %d %d", &n, &k, &p) ;
		for( i = 1; i <= p; ++i ) 
			scanf("%d", &a[i] ) ;
		pq = priority_queue<ii>() ;
		ans = 0 ;
		c = 0 ;
		for( i = 1; i <= n; ++i ) 
			Pos[i].clear(), V[i] = 0 ;
		for( i = 1; i <= p; ++i ) 
			Pos[a[i]].push_back(i) ;
		for( i = 1; i <= n; ++i ) 
			Pos[i].push_back(p + 1) ;
		for( i = 1; i <= p; ++i ) {
			if( V[a[i]] ){ 
				Pos[a[i]].pop_front() ;
				pq.push(ii(Pos[a[i]].front(), a[i])) ;
				continue ;
			}	
			V[a[i]] = 1 ;
			if( c < k ) {
				Pos[a[i]].pop_front() ;
				pq.push(ii(Pos[a[i]].front(), a[i])) ;
				++ans ;
				++c ;
			} else {
				ii temp = pq.top() ; pq.pop() ;
				V[temp.second] = 0 ;
				Pos[a[i]].pop_front() ;
				pq.push(ii(Pos[a[i]].front(), a[i])) ;
				++ans ;
			}
		}
		printf("%d\n", ans) ;
	}
	return 0 ;
}
