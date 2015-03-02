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



const int N = 1111 ;
int n, i, num, t[N], d[N], nt[N], Left, j, vis[N];
char s[33] ;
map<string, int> mp ;
map<int, string> rev ;
ii p[N] ;
vector<int> g[N] ;

int main() {
	while( 1 ) {
		scanf("%d", &n) ;
		if( !n ) 
			break ;
		mp.clear() ;
		rev.clear() ;
		num = 1 ;
		for(i = 1; i <= n; ++i ) {
			scanf("%s", s) ;
			mp[s] = num++ ;
			rev[ num - 1] = s ;
		}
		for( i = 1; i <= n; ++i ) {
			t[i] = 0 ;
			g[i].clear() ;
			d[i] = 0 ;
			vis[i] = 0 ;
		}
		for( i = 1; i < n; ++i ) {
			scanf("%s", s ) ;
			p[i].first = mp[s] ;
			scanf("%s", s ) ;
			p[i].second = mp[s] ;
			g[ p[i].first ].push_back( p[i].second ) ;
			g[ p[i].second ].push_back( p[i].first ) ;
		}
		for( i = 1; i < n; ++i ) {
			t[ p[i].first ]++ ;
			t[ p[i].second ]++ ;
		}
		Left = n ;
		num = 1 ;
		while( Left != 0 ) {
			if( Left == 1 ) {
				for( i = 1; i <= n; ++i ) 
					if( !d[i] ) {
						printf("Winner: %s\n", rev[i].c_str() ) ;
						break ;
					}
				break ;
			}
			for( i = 1; i <= n; ++i ) 
				nt[i] = t[i] ;
			printf("Round #%d\n", num++ ) ;
			for( i = 1; i <= n; ++i ) {
				if( t[i] == 1 ) {
					for( j = 0; j < (int) g[i].size(); ++j ) {
						int who = g[i][j] ;
						if( !d[ who ] && !vis[who] ) {
							d[i] = 1 ;
							printf("%s defeats %s\n", rev[who].c_str(), rev[i].c_str() ) ;
							nt[who]-- ;
							nt[i]-- ;
							vis[who] = 1 ;
							vis[i] = 1 ;
							Left-- ;
							break ;
						}
					}
				}
			}
			for( i = 1; i <= n; ++i ) 
				if( !vis[i] && !d[i] ) {
					printf("%s advances with wildcard\n", rev[i].c_str() ) ;
					break ;
				}
			for( i = 1; i <= n; ++i ) 
				t[i] = nt[i], vis[i] = 0 ;
		}
		putchar('\n') ;
	}
	return 0 ;
}
