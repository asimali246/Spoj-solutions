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


template < typename X > X gcd( X a, X b ) { if( !b ) return a ; else return gcd(b, a%b) ; }

typedef vector<int> vi ;
typedef pair<int, int> ii ;

const int N = 1e6 + 10 ;
const int M = 25010 ;
int t, n, lx, ly, hx, hy, ans, V[M], i, j, b ;
vector<pair<ii, int> > gv[N], gh[N] ;
bool any ;

bool cmp(pair<ii, int> a, pair<ii, int> b ) {
	if( a.first.first != b.first.first ) 
		return a.first.first < b.first.first ;
	if( a.first.second != b.first.second ) 
		return a.first.second < b.first.second ;
	return a.second < b.second ;
}

int main() {
	scanf("%d", &t) ;
	while( t-- ) {
		scanf("%d", &n) ;
		for( i = 0; i < N; ++i ) 
			gv[i].clear(), gh[i].clear() ;
		for( i = 1; i <= n; ++i ) {
			scanf("%d %d %d %d", &lx, &ly, &hx, &hy) ;
			gv[lx].push_back(make_pair(ii(ly, hy), i)) ;
			gv[hx].push_back(make_pair(ii(ly, hy), i)) ;
			gh[ly].push_back(make_pair(ii(lx, hx), i)) ;
			gh[hy].push_back(make_pair(ii(lx, hx), i)) ;
		}
		for( i = 0; i < N; ++i ) {
			sort(gv[i].begin(), gv[i].end(), cmp) ;
			sort(gh[i].begin(), gh[i].end(), cmp) ;
		}
		ans = 0 ;
		for( i = 1; i <= n; ++i ) 
			V[i] = 1 ;
		for( i = 0; i < N; ++i ) {
			hy = -1 ;
			any = false ;
			for( j = 0; j < (int) gv[i].size(); ++j ) {
				pair<ii, int> temp = gv[i][j] ;
				if( temp.first.first > hy ) {
					if( any ) 
						V[b] = 0 ;
					hy = temp.first.second ;
					b = temp.second ;
					any = false ;
				} else {
					any = true ;
					V[temp.second] = 0 ;
					hy = max(hy, temp.first.second) ;
				}
			}
			if( any ) 
				V[b] = 0 ;
		}
		for( i = 0; i < N; ++i ) {
			hx = -1 ;
			any = false ;
			for( j = 0; j < (int) gh[i].size(); ++j ) {
				pair<ii, int> temp = gh[i][j] ;
				if( temp.first.first > hx ) {
					if( any ) 
						V[b] = 0 ;
					hx = temp.first.second ;
					b = temp.second ;
					any = false ;
				} else {
					any = true ;
					V[temp.second] = 0 ;
					hx = max(hx, temp.first.second ) ;
				}
			}
			if( any ) 
				V[b] = 0 ;
		}
		for( i = 1; i <= n; ++i ) 
			if( V[i] ) 
				++ans ;
		printf("%d\n", ans ) ;
	}
	return 0 ;
}
