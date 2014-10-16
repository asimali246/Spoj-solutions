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

const int N = 1e4 + 10;
int t, i, a[N], flag, n ;

int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d", &n);
		for( i = 1; i <= n; ++i )
			scanf("%d", &a[i]);
		a[n + 1] = 0;
		flag = 0;
		for( i = 1; i <= n; ++i ) {
			if( a[i] < 0 ) {
				flag = 1;
				break;
			}
			a[i + 1] -= a[i] ;
			a[i] = 0;
		}
		if( a[n + 1] != 0 )
			flag = 1;
		if( flag )
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}
