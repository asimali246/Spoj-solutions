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
#define INF 1000000000
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;

int h, w, ans, i, j, cs = 1, dp[55][55];
char s[55][55];
int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool valid(int x, int y){
	if( x < 1 || x > h || y < 1 || y > w )
		return false;
	return true;
}

int solve(int r, int c) {
	if( dp[r][c] != -1 )
		return dp[r][c];
	int ans = 1;
	for( int x = 0; x < 8; ++x ) {
		int p, q;
		p = r + dr[x];
		q = c + dc[x];
		if( valid(p, q) &&  s[p][q] == 1 + s[r][c] )
			ans = max( ans , 1 + solve( p, q ) );
	}
	return dp[r][c] = ans;
}

int main() {
	while(1) {
		scanf("%d %d", &h, &w);
		if( !h )
			break;
		getchar();
		for( i = 1; i <= h; ++i ){
			for( j = 1; j <= w; ++j )
				s[i][j] = getchar(), dp[i][j] = -1;
			getchar();
		}
		ans = 0;
		for( i = 1; i <= h; ++i )
			for( j = 1; j <= w; ++j )
				if( s[i][j] == 'A' )
					ans = max( ans, solve( i, j ) );
		printf("Case %d: %d\n", cs++, ans);
	}
	return 0;
}
