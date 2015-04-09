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


int t, n = 7, m = 8, i, j, ans, a[10][10], Taken[10][10] ;
bool V[10][10] ;


bool Valid(int x, int y) {
	if( x > n || y > m ) 
		return false ;
	if( Taken[x][y] ) 
		return false ;
	return true ;
}

ii get(int x, int y) {
	if( y > m ) 
		++x, y = 1 ;
	return ii(x, y) ;
}

void solve(int x, int y) {
	if( x > n ) {
		++ans ;
		return ;
	}
	ii temp ;
	if( Taken[x][y] ) {
		temp = get(x, y + 1 ) ;
		solve(temp.first, temp.second) ;
		return ;
	}
	Taken[x][y] = 1 ;
	int p, q ;
	if( Valid(x, y + 1) ) {
		p = a[x][y] ;
		q = a[x][y + 1] ;
		if( p > q ) 
			swap(p, q) ;
		if( !V[p][q] ) {
			V[p][q] = true ;
			Taken[x][y + 1] = 1 ;
			temp = get(x, y + 2 ) ;
			solve(temp.first, temp.second ) ;
			V[p][q] = false ;
			Taken[x][y + 1] = 0 ;
		}
	}
	if( Valid(x + 1, y) ) {
		p = a[x][y] ;
		q = a[x + 1][y] ;
		if( p > q ) 
			swap(p, q) ;
		if( !V[p][q] ) {
			V[p][q] = true ;
			Taken[x + 1][y] = 1 ;
			temp = get(x, y + 1) ;
			solve( temp.first, temp.second ) ;
			V[p][q] = false ;
			Taken[x + 1][y] = 0 ;
		}
	}
	Taken[x][y] = 0 ;
}


int main() {
	scanf("%d", &t) ;
	while( t-- ) {
		for( i = 1; i <= n; ++i ) 
			for( j = 1; j <= m; ++j ) 
				scanf("%d", &a[i][j] ) ;
		ans = 0 ;
		memset( V, false, sizeof V ) ;
		memset( Taken, 0, sizeof Taken ) ;
		solve(1, 1) ;
		printf("%d\n", ans);
	}
	return 0 ;
}
