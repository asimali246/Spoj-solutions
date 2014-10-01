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
#include <stdint.h>
#include <unistd.h>

 using namespace std;
 
#define ll long long int
#define INF 1000000000
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;

const int MOD = 5e6 ;
const int N = 1e5 ;

int n, k, dp[55][N + 10], i, j, v, z ;

inline void update(int idx, int v ) {

	while( idx <= N ) {

		dp[i][idx] += v;
		idx += ( idx & ( -idx ) ) ;
		dp[i][idx] %= MOD;

	}
}

inline int query(int idx) {
	int sum = 0;
	while( idx > 0 ) {

		sum += dp[i - 1][idx];
		idx -= ( idx & ( -idx ) ) ;
		sum %= MOD;
	}
	if( i - 1 == 1 )
		sum = ( sum + z ) % MOD ;
	return sum;
}

int main() {

	scanf("%d %d", &n, &k) ;

	while( n-- ) {

		scanf("%d", &v);
		if( v != 0 ) {

			for( i = k ; i > 1; --i ) {
				update( v , query( v - 1 ) ) ;
			}
			
		}
		else {
			++z;
			continue;
		}

		i = 1;
		update( v, 1 );

	}

	i = k + 1 ;
	printf("%d\n", query( N ) );

	return 0 ;
}
