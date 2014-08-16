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

char a[555], b[555];
int i, d[555], l, ans, cnt;

int main() {
	while(1) {
		scanf("%s %s", a, b);
		if( a[0] == '*' )
			break;
		l = (int) strlen(a);
		for( i = 0; i < l; ++i )
			d[i] = ( a[i] == b[i] ) ? 1: 0;
		cnt = ( d[0] == 0 ) ? 1 : 0;
		ans = 0;
		if( cnt )
			ans = 1;
		for( i = 1; i < l; ++i ) {
			if( cnt && d[i])
				cnt = 0;
			else
			if( !cnt && d[i] == 0 )
				++ans, cnt = 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}
