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
typedef pair<int, int> ii;

const int N = 1e8 + 10;
const int S = 10000;
int i, j, prime[S], k, l, maxk;
bool bs[S + 10] ;
vi ans;

int main() {
	l = 1;
	for( i = 2; i <= S ; ++i ) 
		if( !bs[i] ) {
			prime[l++] = i;
			for( j = i + i; j <= S; j += i )
				bs[j] = 1;
		}
	--l;
	maxk = N / S ;
	ans.clear();
	ans.push_back(1);
	for( k = 0; k <= maxk ; ++k ) {
		memset(bs, 0, sizeof bs);
		int strt = k * S;
		for( i = 1; i <= l; ++i ) {
			int id = ( strt + prime[i] - 1 ) / prime[i];
			j = max( id , 2 ) * prime[i] - strt;
			for( ; j < S; j += prime[i] ) 
				bs[j] = 1;
		}
		if( k == 0 )
			bs[0] = bs[1] = true;
		for( i = 0; i < S; ++i )
			if( !bs[i] && i + strt <= N) 
				ans.push_back(i + strt);
	}
	printf("%d\n", ans[1]);
	for( i = 2; i < ans.size(); ++i ) {
		if( i % 100 == 1 )
			printf("%d\n", ans[i] );
	}
	return 0;
}
