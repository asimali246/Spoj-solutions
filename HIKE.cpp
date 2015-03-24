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



const int N = 55 ;
int n, a, b, c, i, j, d;
char s[N][N] ;
int dp[N][N][N] ;
queue<pair<ii, ii> > q ;
bool found = false ;
vector<int> g[N][33] ;
char temp[5] ;

void Push(int u, char c, int x, int y) {
	for( j = 0; j < (int) g[u][c - 'a' + 1].size(); ++j ) {
		int v = g[u][c - 'a' + 1][j] ;
		if( dp[v][x][y] == -1 ) {
			q.push(make_pair(ii(v, x), ii(y, d + 1) ) ) ;
			dp[v][x][y] = 1 ;
		}
	}
}
void Process() {
	Push(a, s[b][c], b, c) ;
	Push(b, s[a][c], a, c) ;
	Push(c, s[a][b], a, b) ;
}

int main() {
	while( true ) {
		scanf("%d", &n) ;
		if( !n ) 
			break ;
		for( i = 1; i <= n; ++i ) 
			for( j = 1; j <= n; ++j ) 
				for(int k = 1; k <= n; ++k )
					dp[i][j][k] = -1 ;
		for( i = 1; i <= n; ++i ) 
			for( j = 1; j <= 26; ++j ) 
				g[i][j].clear() ;
		scanf("%d %d %d", &a, &b, &c) ;
		getchar() ;
		q = queue<pair<ii, ii> >() ;
		for( i = 1; i <= n; ++i ) {
			for( j = 1; j <= n; ++j ) {
				scanf("%s", temp) ;
				s[i][j] = temp[0] ;
				g[i][ s[i][j] - 'a' + 1 ].push_back(j) ;
			}
		}
		dp[a][b][c] = 1 ;
		q.push( make_pair(ii(a, b), ii(c, 0) ) ) ;
		found = false ;
		while( !q.empty() ) {
			pair<ii, ii> temp = q.front() ;
			a = temp.first.first ;
			b = temp.first.second ;
			c = temp.second.first ;
			d = temp.second.second ;
			q.pop() ;
			if( a == b && a == c ) {
				found = true ;
				break ;
			}
			Process() ;
		}
		if( found ) 
			printf("%d\n", d);
		else
			printf("impossible\n");
	}
	return 0 ;
}
