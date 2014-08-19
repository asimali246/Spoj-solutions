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

const int N = 50100;
int n, i, c[5], a[2*N], mx, ans, j;

int main() {
	scanf("%d", &n);
	getchar();
	c[1] = c[2] = c[3] = c[4] = n;
	for( i = 1; i <= 2*n; ++i )
		a[i] = getchar() - 64, c[a[i]]--;
	for( i = 1; i <= 2*n; ++i ) {
		mx = 0;
		for( j = 1; j <= 4; ++j){
			if( a[i] != j && a[i-1] != j){
				if( c[j] > mx )
					mx = c[j], ans = j;
				if( c[j] == mx && a[i+1] == j )
					ans = j;
			}
		}
		putchar(ans + 64);
		c[ans]--;
		a[i] = ans;
	}
	putchar('\n');
	return 0;
}
