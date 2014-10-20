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
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii ;

const int N = 1e8 + 10;
const int S = 10000;
int  x, i, j, prime[S], tp[N / 10], l, mxk, k, m ;
bool bs[S];
double ans;

inline int solve() {
	int l = 1, h = m, mid;
	int ans = INF;
	while( l <= h ) {
		mid = ( l + h ) >> 1;
		if( tp[mid] <= x ) 
			l = mid + 1, ans = mid;
		else
			h = mid - 1;
	}
	if( ans == INF )
		ans = 0;
	return ans;
}
int main() {
	for( i = 2; i < S; ++i ) {
		if( !bs[i] ) {
			for( j = i + i; j < S; j += i ) 
				bs[j] = true;
			prime[++l] = i ;
		} 
	}
	mxk = N / S;
	for( k = 0; k < mxk; ++k ) {
		int strt = k * S ;
		memset( bs, false, sizeof bs );
		for( i = 1; i <= l; ++i ) {
			int id = ( strt + prime[i] - 1 ) / prime[i] ;
			j = max( id, 2 ) * prime[i] - strt ; 
			for( ; j < S; j += prime[i] ) 
				bs[j] = true;
		}
		if( k == 0 )
			bs[0] = bs[1] = true;
		for( i = 0; i < S; ++i ) 
			if( !bs[i] ) 
				tp[++m] = strt + i;
	}
	while( 1 ) {
		scanf("%d", &x );
		if( !x )
			break;
		int tpr = solve();
		ans = abs( (double)tpr  - ( double ) x / ( double ) log(x) ) ;
		ans = ans / (double) tpr ;
		printf("%.1lf\n", ans * 100.0);
	}
	return 0;
}
