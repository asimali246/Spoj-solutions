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

const int N = 301000;
const int M = 2e5 + 1000;
int n, q, i, t[N], a[N], pos[1<<20], j, ans[M];
pair<ii, int> p[M];

void update(int id, int v) {
	while( id <= n ) 
		t[id] += v, id += ( id & (-id) );
}
int query(int id ) {
	int sum = 0;
	while( id > 0 )
		sum += t[id], id -= (id & (-id) );
	return sum;
}
int answer(int l, int r) {
	return query(r) - query(l - 1);
}
bool cmp(pair<ii, int> a, pair<ii, int> b) {
	if( a.first.second != b.first.second )
		return a.first.second < b.first.second;
	if( a.first.first != b.first.first)
		return a.first.first < b.first.first;
	return a.second <= b.second;
}
int main() {
	scanf("%d", &n);
	for( i = 1; i <= n; ++i )
		scanf("%d", &a[i]);
	scanf("%d", &q);
	for( i = 1; i <= q; ++i )
		scanf("%d %d", &p[i].first.first, &p[i].first.second), p[i].second = i;
	sort(p + 1, p + q + 1, cmp);
	j = 1;
	for( i = 1; i <= n; ++i ) {
		if( pos[a[i]] ) 
			update(pos[a[i]], -1);
		pos[a[i]] = i;
		update(i, 1);
		while( j <= q && p[j].first.second == i ) 
			ans[p[j].second] = answer(p[j].first.first, p[j].first.second), ++j;
	}
	for( i = 1; i <= q; ++i )
		printf("%d\n", ans[i]);
	return 0;
}
