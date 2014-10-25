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

const int N = 1e6 + 10;
int t, a, b, n, i, j, d[N], tsum[11][N] ;

int main() {
	for( i = 2; i < N; ++i ) {
		if( !d[i] ) {
			for( j = i ; j < N; j += i ) 
				d[j]++;
		}
	}
	tsum[0][1] = 1 ;
	for( i = 0; i <= 10; ++i ){
		for( j = 2; j < N; ++j ) {
			tsum[i][j] = tsum[i][j - 1];
			if( d[j] == i )
				tsum[i][j]++;
		}
	}
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d %d %d", &a, &b, &n );
		printf("%d\n", tsum[n][b] - tsum[n][a - 1]);
	}
	return 0;
}
