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



const int N = 16 ;
int i, j, x, y, a[N][N], S[N][N], ans;
char ch ;
ii p[N * N] ;
bool flag = false ;
 
bool solve( int mask ) {

	for( i = 1; i <= x; ++i ) 
		for( j = 1; j <= y; ++j ) 
			S[i][j] = a[i][j] ;
	
	for( j = 0; j < y; ++j ) {
		if( mask & ( 1 << j ) ) {
			S[1][j + 1] = 1 - S[1][j + 1] ;
			S[1][j] = 1 - S[1][j] ;
			S[1][j + 2] = 1 - S[1][j + 2] ;
			S[2][j + 1] = 1 - S[2][j + 1] ;
			p[ ans ].first = 1 ;
			p[ ans ].second = j + 1 ;
			++ans ; 
		}
	}
	
	for( i = 2; i <= x; ++i ) {
		for( j = 1; j <= y; ++j ) {
			if( !S[i - 1][j] ) {
				S[i][j] = 1 - S[i][j] ;
				S[i + 1][j] = 1 - S[i + 1][j] ;
				S[i][j - 1] = 1 - S[i][j - 1] ;
				S[i][j + 1] = 1 - S[i][j + 1] ;
				S[ i - 1][j] = 1 - S[i - 1][j] ;
				p[ans].first = i ;
				p[ans].second = j ;
				++ans ;
			}
		}
	}

	for( i = 1; i <= x; ++i ) 
		for( j = 1; j <= y; ++j ) 
			if( !S[i][j] ) 
				return false ;

	return true ;
}

int main() {
	while( 1 ) {
		scanf("%d %d", &y, &x ) ;
		flag = false ;
		if( x == 0 ) 
			break ;
		getchar() ;
		for( i = 1; i <= x; ++i ) {
			for( j = 1; j <= y; ++j ) {
				ch = getchar() ;
				a[i][j] = ch - '0' ;
			}
			getchar() ;
		}
		for( int i = 0; i < ( 1 << y ) ; ++i ) {
			ans = 1 ;
			if( solve(i) ) {
				flag = true ;
				break ;
			}
		}
		if( flag ) {
			printf("%d\n", ans - 1);
			for( i = 1; i < ans; ++i ) 
				printf("%d %d\n", p[i].second, p[i].first ) ;
		}
		else 
			printf("-1\n");
	}
	return 0 ;
}
