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

const int N = 1 << 20;
int t, n, i, j, ans, cnt;

int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d", &n);
		ans = 0;
		for( i = 2; i * i <= n; ++i ) {
			cnt = 0;
			while( n % i == 0 )
				cnt++, n /= i;
			ans = max(ans, cnt);
		}
		if(n > 1)
			ans = max(ans, 1);
		printf("%d\n", ans);
	}
	return 0;
}
