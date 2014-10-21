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

const int N = 2e5 + 10;
int q, i, l, h, m, rev[N], s[N], pos, v, t[N], vis[N], av, tl, ans;
map<int, int> cmp ;
pair<char, int> p[N];
char ch;

void update(int id, int v) {
	while( id < N ) {
		t[id] += v;
		id += ( id & (-id) );
	}
}

int query(int id) {
	int sum = 0;
	while( id > 0 ) {
		sum += t[id];
		id -= ( id & (-id) );
	}
	return sum;
}

int main() {
	scanf("%d", &q);
	getchar();
	tl = 1;
	for( i = 1; i <= q; ++i ) {
		scanf("%c %d", &ch, &v);
		++pos;
		p[pos].first = ch;
		p[pos].second = v;
		if( ch != 'K' )
			s[tl++] = v;
		getchar();
	}
	--tl;
	sort( s + 1, s + tl + 1);
	v = 1;
	for( i = 1; i <= tl; ++i ) {
		if( i == 1 || s[i] != s[i - 1] ) {
			cmp[s[i]] = v;
			rev[v] = s[i];
			++v;
		}
	}
	tl = --v;
	for( i = 1; i <= q; ++i ) {
		ch = p[i].first ;
		v = p[i].second ;
		if(ch != 'K' ) 
			av = cmp[v];
		if( ch == 'I' ) {
			if( !vis[av] ) {
				vis[av] = 1;
				update( av, 1 );
			}
		}
		if( ch == 'D' ) {
			if( vis[av] ) {
				vis[av] = 0;
				update( av, -1 );
			}
		}
		if( ch == 'K' ) {
			l = 1, h = tl;
			ans = INF;
			while( l <= h ) {
				m = ( l + h ) >> 1;
				int vm = query( m ) ;
				if( vm > v ) 
					h = m - 1;
				else
				if( vm < v ) 
					l = m + 1;
				else {
					ans = m;
					h = m - 1;
				}
			}
			if( ans == INF )
				printf("invalid\n");
			else
				printf("%d\n", rev[ans]);
		}
		if( ch == 'C' ) {
			printf("%d\n", query( av - 1 ) );
		}
	}
	return 0;
}
