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

const int N = 1e8 ; 
const int S = 10000;
int i, j, prime[S + S], ans[N / 10], l, k, maxk, p, flag;
bool bs[S + 10];
ll n;

int main() {
	l = 1;
	for( i = 2; i <= S ; ++i ) {

		if( !bs[i] ) {

			for( j = i + i; j <= S; j += i )
				bs[j] = true;

			prime[l++] = i ;
		}
	}

	--l ; 
	maxk = N / S ;
	p = 1;

	for( k = 0; k <= maxk ; ++k ) {

		int strt = k * S ; 
		memset( bs, 0, sizeof bs ) ;

		for( i = 1; i <= l; ++i ) {
			int id = (strt + prime[i] - 1 ) / prime[i];
			j = max( id, 2 ) * prime[i] - strt ;
			for( ; j < S ; j += prime[i] ) 
				bs[j] = true;
		}

		if( k == 0 )
			bs[0] = bs[1] = true;

		for( j = 0; j < S; ++j )
			if( !bs[j] )
				ans[p++] = j + strt;

	}

	--p ; 
	while( 1 ) {

		scanf("%lld", &n) ;
		if( n == 1 ) {
			printf("1^1\n");
			continue ;
		}
		if( !n )
			break;
		flag = 0;

		for( i = 1; i <= p ; ++i ) {

			if( (ll) ans[i] * ans[i] > n ) 
				break;

			if( n % (ll) ans[i] == 0 ) {

				int cnt = 0;

				while( n % (ll) ans[i] == 0 )
					cnt++, n /= (ll) ans[i] ;

				if( flag ) 
					putchar(' ');

				flag = 1;
				printf("%d^%d", ans[i], cnt); 
				
			}
		}

		if( n > 1 ) {
			if( flag )
				putchar(' ') ; 
			printf("%lld^1", n);
		}

		putchar('\n');

	}

	return 0;
}
