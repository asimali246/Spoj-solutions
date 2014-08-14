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
#define INF 2147483647
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1<<17;
int t, n, i, a[N], j, ans[1010], num;

int main() {
	for(i = 2; i < N; ++i )
		if( !a[i] )
			for( j = i * 2; j < N; j += i )
				a[j]++;
	num = 1;
	for( i = 1; i < N && num <= 1000; ++i )
		if( a[i] >= 3)
			ans[ num++ ] = i;
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}
	return 0;
}
