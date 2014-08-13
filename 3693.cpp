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

const int N = 1<<18;
int n, a[N], x, y, i, q;
char ch;
ii t[4*N];

void build( int id, int l, int r ){
	if( l == r ){
		t[id].first = a[l];
		t[id].second = 0;
		return ;
	}
	int m = ( l + r ) >> 1;
	build( id << 1, l, m );
	build( (id << 1) | 1 , m+1, r );
	if( t[ id << 1 ].first >= t[ (id << 1) | 1].first){
		t[id].first = t[id<<1].first;
		t[id].second = max(t[ id << 1 ].second, t[ (id << 1 ) | 1].first);
	}
	else{
		t[id].first = t[( id << 1 ) | 1].first;
		t[id].second = max( t[ (id << 1) | 1 ].second, t[ id << 1 ].first);
	}
}
void update(int id, int l, int r, int x, int v){
	if( l == r && l == x){
		t[id].first = v;
		t[id].second = 0;
		return;
	}
	int m = ( l + r ) >> 1;
	if( x <= m )
		update( id << 1, l, m, x, v);
	else
		update( (id << 1) | 1, m+1, r, x, v);
	if( t[ id << 1 ].first >= t[ (id << 1) | 1].first){
		t[id].first = t[id<<1].first;
		t[id].second = max(t[ id << 1 ].second, t[ (id << 1 ) | 1].first);
	}
	else{
		t[id].first = t[( id << 1 ) | 1].first;
		t[id].second = max( t[(id << 1) | 1].second, t[ id << 1 ].first);
	}
}
ii query(int id, int l, int r, int x, int y) {
	if( l == x && r == y ){
		return t[id];
	}
	int m = ( l + r ) >> 1;
	if( y <= m )
		return query( id << 1, l, m, x, y );
	else
	if( x > m )
		return query( (id << 1) | 1, m+1, r, x, y );
	else{
		ii a = query( id << 1, l, m, x, m );
		ii b = query( ( id << 1 ) | 1, m+1, r, m+1, y);
		if( a.first >= b.first )
			return ii( a.first, max(a.second, b.first));
		else
			return ii(b.first, max(a.first, b.second));
	}
}
int main() {
	scanf("%d", &n);
	for( i = 1; i <= n; ++i )
		scanf("%d", &a[i]);
	build(1, 1, n);
	scanf("%d", &q);
	getchar();
	while( q-- ) {
		scanf("%c %d %d", &ch, &x, &y);
		getchar();
		if( ch == 'U' )
			update(1, 1, n, x, y);
		else{
			ii temp = query(1, 1, n, x, y);
			printf("%d\n", temp.first + temp.second);
		}
	}
	return 0;
}
