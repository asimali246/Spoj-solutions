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
int n, m, d, i, vis[N], p[N * 10], j, a[N], l, sum[N];
bool flag ;

inline bool check(int pos) {
	if( pos <= 2 ) 
		return true ;
	bool temp = true ;
	for( i = 1; i < pos; ++i ) 
		sum[i] = sum[i - 1] + a[i] ;
	for( i = 2; i < pos; ++i ) {
		for( j = 2; j <= d && i - j >= 0 ; ++j ) {
			if( !p[ sum[i] - sum[i - j]] ) {
				temp = false ;
				break ;
			}
		} 
		if( !temp ) 
			break ;
	}
	return temp ;
}

void solve(int pos) {
	if( check(pos) ) {
		if( pos == l + 1 ) {
			flag = true ;
			return ;
		}
		for( int j = n; j <= m; ++j ) {
			if( !vis[j] ) {
				a[pos] = j ;
				vis[j] = 1 ;
				solve( pos + 1 ) ;
				if( flag ) 
					return ;
				vis[j] = 0 ;
			}
		}
	}
}

int main() {
	for( i = 2; i < N * 10; ++i ) {
		if( !p[i] ) {
			for( j = i + i; j < N * 10; j += i ) 
				p[j] = 1 ;
		}
	}
	while( 1 ) {
		memset( vis, 0, sizeof vis ) ;
		scanf("%d %d %d", &n, &m, &d ) ;
		if( !n ) 
			break ;
		l = m - n + 1 ;
		flag = false ;
		solve( 1 ) ;
		if( !flag ) 
			printf("No anti-prime sequence exists.\n") ;
		else {
			for( i = 1; i <= l; ++i ) {
				if( i > 1 ) 
					putchar(',') ;
				printf("%d", a[i] ) ;
			}
			printf("\n") ;
		}
	}
	return 0 ;
}
