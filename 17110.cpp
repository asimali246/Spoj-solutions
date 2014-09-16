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

const int N = 1010;
int t, n, r, R, i, flag;
pair<ii, int> p[N];

int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d", &n);
		for( i = 1; i <= n; ++i ) {
			scanf("%d %d", &r, &R);
			p[i].first.first = R, p[i].first.second = r;
			p[i].second = i;
		}
		flag = 0;
		sort( p + 1, p + n + 1 );
		if(p[n].first.second > p[n - 1].first.first )
			printf("%d\n", p[n].second);
		else {
			for( i = 1; i < n; ++i )
				if(p[i].first.second > p[n].first.first ) {
					printf("%d\n", p[i].second);
					flag = 1;
					break;
				}
			if( !flag )
				puts("-1");
		}
	}
	return 0;
}
