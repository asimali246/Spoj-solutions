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

int t, a[5], fa[5], i, n, ans, m, ca[5], ta[5] ; 
queue<int> q ;
bool dp[50][50][50][50] ;
bool flag ;

void process( int j ) {
	int i, k;
	if( a[j] != 0 ) {
		for( i = 1; i < j; ++i ) 
			ta[i] = a[i] ;
		ta[j] = 0 ;
		for( i = j + 1; i <= n; ++i ) 
			ta[i] = a[i] ;
		if( dp[ta[1]][ta[2]][ta[3]][ta[4]] != true ) {
			dp[ta[1]][ta[2]][ta[3]][ta[4]] = true ;
			for( i = 1; i <= n; ++i ) 
				q.push(ta[i]) ;
			q.push(m + 1) ;
		}
	}
	for( i = 1; i <= n; ++i ) {
		if( j != i ) {
			if( ca[i] - a[i] > 0 && a[j] != 0 ) {
				for( k = 1; k <= n; ++k ) 
					ta[k] = a[k] ;
				int temp = min(a[j], ca[i] - a[i] ) ;
				ta[i] += temp ;
				ta[j] -= temp ;
				if( dp[ta[1]][ta[2]][ta[3]][ta[4]] != true ) {
					dp[ta[1]][ta[2]][ta[3]][ta[4]] = true ;
					for( k = 1; k <= n; ++k ) 
						q.push(ta[k]) ;
					q.push(m + 1) ;
				}
			}
		}
	}
}

void check() {
	while( !q.empty() ) {
		for( i = 1; i <= n; ++i ) 
			a[i] = q.front(), q.pop() ;
		m = q.front(), q.pop() ;
		flag = true ;
		for( i = 1; i <= n; ++i ) 
			if(a[i] != fa[i]) {
				flag = false ;
				break ;
			}
		if( flag ) {
			ans = m ;
			return ;
		}
		flag = true ;
		for( i = 1; i <= n; ++i ) {
			if( a[i] != 0 ) {
				flag = false ;
				break ;
			}
		}
		if( flag ) 
			continue ;
		for( i = 1; i <= n; ++i ) 
			process(i) ;
	}
}
int main() {
	scanf("%d", &t) ;
	while( t-- ) {
		scanf("%d", &n) ;
		for( i = 1; i <= n; ++i ) 
			a[i] = 0, ta[i] = 0 ;
		for( i = 1; i <= n; ++i ) 
			scanf("%d", &a[i] ), ca[i] = a[i] ;
		for( i = 1; i <= n; ++i ) 
			scanf("%d", &fa[i] ) ;
		q = queue<int>() ;
		memset(dp, false, sizeof dp) ;
		for( i = 1; i <= n; ++i ) 
			q.push(a[i]) ;
		q.push(0) ;
		dp[a[1]][a[2]][a[3]][a[4]] = true ;
		ans = -1 ;
		check() ;
		if( ans == -1 ) 
			puts("NO") ;
		else
			printf("%d\n", ans) ;
	}
	return 0 ;
}
