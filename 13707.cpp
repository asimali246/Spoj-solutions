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

const int N = 20100;
int t, n, vis[N], i, ans;

int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d", &n);
		if(vis[n - 1] && vis[n + 1])
			vis[n] = 1, --ans;
		else
		if( vis[n - 1] )
			vis[n] = 1;
		else
		if( vis[n + 1] )
			vis[n] = 1;
		else
			vis[n] = 1, ++ans;
		printf("%d\n", ans);
	}
	puts("Justice");
	return 0;
}
