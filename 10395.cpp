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

const int N = 1<<20;
int t, a, b, ans[N], i, j;
bitset<N> bs;
vi p;

int main() {
	bs.set(), p.clear();
	for( i = 2; i < N; ++i )
		if(bs[i]) {
			for( j = i + i; j < N; j += i ) 
				bs[j] = 0;
			p.push_back(i);
		}
	bs[0] = bs[1] = 0;
	for( i = 0; i < (int)p.size(); ++i ) {
		if(p[i] > 1000)
			break;
		j = p[i];
		while( j < N ) {
			if( bs[(j * p[i] - 1) / (p[i] - 1)] )
				ans[j] = 1;
			j *= p[i];
		}
	}
	for( i = 1; i < N ; ++i )
		ans[i] += ans[i-1];
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d %d", &a, &b);
		printf("%d\n", ans[b] - ans[a-1]);
	}
	return 0;
}
