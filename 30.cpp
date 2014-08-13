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

const int N = 1<<14;
int t, n, i, p[N], m, id, c, num, ans;
char s[15];
map<string, int> mp;
vector<pair<int, ii> > e;

int findSet(int x){
	return (p[x] == x)?x:p[x] = findSet(p[x]);
}
bool sameSet(int i, int j) {
	return findSet(i) == findSet(j);
}
void Union(int i, int j) {
	p[findSet(j)] = p[findSet(i)];
}
int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d", &n);
		num = 1;
		for( i = 1; i <= n; ++i )
			p[i] = i;
		e.clear();
		for( i = 1; i <= n; ++i ) {
			scanf("%s", s);
			mp[s] = num++;
			scanf("%d", &m);
			while( m-- ) {
				scanf("%d %d", &id, &c);
				e.push_back( make_pair(c, ii(i, id)) );
			}
		}
		sort(e.begin(), e.end());
		ans = 0;
		for(i = 0; i < (int)e.size(); ++i ) {
			pair<int, ii> temp = e[i];
			if(!sameSet( temp.second.first, temp.second.second )){
				ans += temp.first;
				Union(temp.second.first, temp.second.second);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
