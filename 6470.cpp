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

const int N = 100000000;
const int SQRT_MAXN = 100000;
const int S = 10000;
int t, n, i, j, prime[SQRT_MAXN], l, srt, k, mxk, strt, id, flag, cnt;
bool bs[S + 10];	
vi ans;

int main() {
	ans.clear();
	srt = (int) sqrt(N + 0.0);
	for( i = 2; i <= srt; ++i ) {
		if(!bs[i]) {
			prime[l++] = i;	
			if(i * 1LL * i <= srt)
				for( j = i * i; j <= srt; j += i )
					bs[j] = true;
		}
	}
	--l;
	mxk = N / S;
	for( k = 0; k <= mxk; ++k ) {
		memset(bs, 0, sizeof bs);
		strt = k * S;
		for( i = 0; i <= l; ++i ) {
			id = (strt + prime[i] - 1) / prime[i];
			j = max(id, 2) * prime[i] - strt;
			for( ; j < S; j += prime[i])
				bs[j] = true;
		}
		if( k == 0 )
			bs[0] = bs[1] = true;
		for( i = 0; i < S; ++i )
			if(!bs[i]) {
				ans.push_back(i + strt);
				++cnt;
				if(cnt > 5000000) {
					flag = 1;
					break;
				}				
			}
		if(flag)
			break;
	}
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d", &n);
		printf("%d\n", ans[n - 1]);
	}
	return 0;
}
