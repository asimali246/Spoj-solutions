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
 
typedef vector<int> vi;
typedef pair<int, int> ii;


const int N = 111 ;
int n, i, vis[N], S[N][2], x, j ;
char s[11] ;
bool ans ;
queue<int> q ;

void dfs(int u, int v) {
	vis[u] = v ;
	q.push(u) ;
	if( S[u][1] ) {
		if( vis[u] ) {
			if( vis[ S[u][0] ] == 0 ) {
				ans = false ;
				return ;
			}
			if( vis[ S[u][0] ] == 1 ) 
				return ;
			dfs(S[u][0], 1) ;
		}
		else {
			if( vis[ S[u][0] ] == 1 ) {
				ans = false ;
				return ;
			}
			if( vis[ S[u][0] ] == 0 )
				return ;
			dfs( S[u][0], 0 ) ;
		}
	}
	else {
		if( vis[u] ) {
			if( vis[ S[u][0] ] == 1 ) {
				ans = false ;
				return ;
			}
			if( vis[ S[u][0] ] == 0 ) 
				return ;
			dfs( S[u][0], 0 ) ;
		}
		else {
			if( vis[ S[u][0] ] == 0 ) {
				ans = false ;
				return ;
			}
			if( vis[ S[u][0] ] == 1 ) 
				return ;
			dfs( S[u][0], 1 ) ;
		}
	}
}

int main() {
	while( 1 ) {
		scanf("%d", &n) ;
		if( !n ) 
			break ;
		for( i = 1; i <= n; ++i ) {
			scanf("%d %s", &x, s ) ;
			S[i][0] = x ;
			S[i][1] = ( s[0] == 'f' ? 0 : 1 ) ;
		}
		memset( vis, -1, sizeof vis ) ;
		for( i = 1; i <= n; ++i ) {
			if( vis[i] == -1 ) {
				ans = true ;
				q = queue<int> () ;
				dfs(i, 0) ;
				if( !ans ) {
					while( !q.empty() ) {
						x = q.front() ;
						vis[x] = -1 ;
						q.pop() ;
					}
				}
			}
		}
		for( i = 1; i <= n; ++i ) {
			if( vis[i] == -1 ) {
				ans = true ;
				q = queue<int> () ;
				dfs(i, 1) ;
				if( !ans ) {
					while( !q.empty() ) {
						x = q.front() ;
						vis[x] = -1 ;
						q.pop() ;
					}
				}
			}
		}
		ans = false ;
		for( i = 1; i <= n; ++i ) {
			if( vis[i] == -1 ) {
				ans = true ;
				break ;
			}
		}
		puts( ans ? "PARADOX" : "NOT PARADOX" ) ;
	}
	return 0 ;
}
