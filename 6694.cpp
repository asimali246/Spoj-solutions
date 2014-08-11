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

int n, d, i, ans[1010];

int main() {
	d=7;
	ans[1]=5;
	for( i = 2 ; i <= 1000; ++i )
		ans[i] = ans[i-1] + d, d += 3;
	while(1) {
		scanf("%d", &n);
		if(!n)
			break;
		printf("%d\n", ans[n]);
	}
	return 0;
}
