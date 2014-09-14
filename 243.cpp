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

const int N = 555;
int t, n, W[N][N], M[N][N], P[N], i, j, v, w, m, r1, r2, ans[N];
queue<int> q;

int main() {
	scanf("%d", &t);
	while( t-- ) {
		q = queue<int>();
		scanf("%d", &n);
		for( i = 1; i <= n; ++i ) {
			scanf("%d", &v), w = v;
			for( j = 1; j <= n; ++j ) {
				scanf("%d", &v);
				W[w][v] = j;
			}
		}
		for( i = 1; i <= n; ++i ) {
			M[i][0] = 1;
			scanf("%d", &v), m = v;
			for( j = 1; j <= n; ++j ) {
				scanf("%d", &M[m][j]);
			}
			q.push(i);
			P[i] = 0;
		}
		while(!q.empty()) {
			m = q.front(); q.pop();
			w = M[m][M[m][0]];
			M[m][0]++;
			if(P[w] == 0 ) 
				P[w] = m;
			else {
				r1 = W[w][P[w]];
				r2 = W[w][m];
				if( r1 < r2 ) 
					q.push(m);
				else
					q.push(P[w]), P[w] = m;
			}
		}
		for( i = 1; i <= n; ++i )
			ans[P[i]] = i;
		for( i = 1; i <= n; ++i )
			printf("%d %d\n", i, ans[i]);
	}
	return 0;
}
