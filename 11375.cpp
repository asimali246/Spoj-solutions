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

const int N = 10100;
int t, n, r, vis[N], cs = 1, i, flag;
ii p[N];

int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d %d", &n, &r);
		for( i = 1; i < N; ++i )
			vis[i] = 0;
		flag = 0;
		for( i = 1; i <= r; ++i )
			scanf("%d %d", &p[i].first, &p[i].second), vis[p[i].first] = 1;
		for( i = 1; i <= r; ++i )
			if(vis[p[i].second]) {
				printf("Scenario #%d: spied\n", cs++);
				flag = 1;
				break;
			}
		if(!flag)
			printf("Scenario #%d: spying\n", cs++);
	}
	return 0;
}
