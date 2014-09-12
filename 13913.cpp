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

ll t, n, ans;

int main() {
	scanf("%lld", &t);
	while( t-- ) {
		scanf("%lld", &n);
		ans = n - 2;
		ans = ans >> 1;
		if( (n - 2)&1 )
			++ans;
		ans = (ans * ans ) % n;
		printf("%lld\n", ans);
	}
	return 0 ;
}
