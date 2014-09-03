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

int t, n, i, num, x, a[1111], pos;
queue<int> q;

void solve() {
	pos = 1;
	while( num != 0 ) {
		a[pos++] = num % 2;
		num /= 2;
	}
	for( i = pos - 1; i >= 1; --i )
		printf("%d", a[i]);
	putchar('\n');
}
int main() {
	scanf("%d", &t);
	while( t-- ) {
		q = queue<int>();
		scanf("%d", &n);
		num = 1;
		q.push(1 % n);
		while( !q.empty() ) {
			x = q.front(); q.pop();
			if( x == 0 ) {
				solve();
				break;
			}
			q.push(( x * 10 ) % n);
			q.push(( x * 10 + 1) % n);
			++num;
		}
	}
	return 0;
}
