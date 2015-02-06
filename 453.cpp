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
int a[N][N], i, j, n, t ;

int main() {
	scanf("%d", &t) ;
	while( t-- ) {
		scanf("%d", &n) ;
		for( i = 1; i <= n; ++i ) 
			for( j = 1; j <= i; ++j ) 
				scanf("%d", &a[i][j] ) ;
		for( i = n - 1 ; i >= 1; --i ) {
			for( j = 1; j <= i; ++j ) 
				a[i][j] = a[i][j] + max( a[i + 1][j], a[i + 1][j + 1] ) ;
		}
		printf("%d\n", a[1][1]) ;
	}
	return 0 ;
}
