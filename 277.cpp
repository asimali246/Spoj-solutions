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

const int N = 1010;
int t, m, n, i, j, ans, h[N], s[N][N], tp, mx;
stack<int> st;
char ch;

int main() {

	scanf("%d", &t);
	while( t-- ) {

		scanf("%d %d", &m, &n);

		for( i = 1; i <= m; ++i ) {
			for( j = 1; j <= n; ++j ) {
				cin >> ch;
				s[i][j] = ( (ch == 'R') ? 0 : 1 ) ;
			}
		}

		for( i = 1; i <= n; ++i )
			h[i] = 0;

		ans = -INF;

		for( i = 1; i <= m; ++i ) {

			for( j = 1; j <= n; ++j ) {
				if( s[i][j] == 0 )
					h[j] = 0;
				else
					++h[j];
			}

			st = stack<int> ();
			j = 1; 

			while( j <= n ) {

				if( st.empty() || h[st.top()] <= h[j] ) 
					st.push( j++ );

				else {

					tp = st.top() ; st.pop() ;
					mx = h[tp] * ( st.empty() ? j - 1 : j - st.top() - 1); 
					ans = max( ans, mx );
				}
			}

			while( !st.empty() ) {
				tp = st.top() ; st.pop() ;
				mx = h[tp] * ( st.empty() ? j - 1 : j - st.top() - 1 ) ;
				ans = max( ans, mx );
			}

		}
		if( m <= 0 || n <= 0 )
			ans = 0;
		printf("%d\n", ans * 3) ;
	}
	return 0 ;
}
