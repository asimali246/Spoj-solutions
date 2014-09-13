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
int t, m, v, c[N], a, b;
ll ans;
priority_queue<int> mx;
priority_queue<int, vector<int>, greater<int> > mn;

int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d", &m);
		while( m-- ) 
			scanf("%d", &v), c[v]++, mx.push(v), mn.push(v);
		while(1) {
			a = mx.top(); mx.pop();
			if(c[a]) {
				c[a]--;
				break;
			}
		}
		while(1) {
			b = mn.top(); mn.pop();
			if(c[b]) {
				c[b]--;
				break;
			}
		}
		ans += (ll) (a - b);
	}
	printf("%lld\n", ans);
	return 0;
}
