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

int r[1333], c[6666], rr[1333], rc[6666], st[1333];
int x, y, z, i;
char ch, s[1010];

int main() {
	st[0] = -5677;
	for( i = 1; i <= 1234; ++i )
		r[i] = i, rr[i] = i, st[i] = st[i-1] + 5678;;
	for( i = 1; i <= 5678; ++i )
		c[i] = i, rc[i] = i;
	while(gets(s) && strlen(s) != 0 ){
		ch = s[0];
		if( ch == 'W' ){
			sscanf(s, "%c %d", &ch, &z);
			x = z / 5678;
			x += (( z % 5678) ? 1 : 0 );
			y = st[x];
			y = z - y + 1;
			x = rr[x];
			y = rc[y];
			printf("%d %d\n", x, y);
		}
		else {
			sscanf(s, "%c %d %d", &ch, &x, &y);
			if( ch == 'R' ){
				rr[r[x]] = y;
				rr[r[y]] = x;
				swap(r[x], r[y]);
			}
			if( ch == 'C' ){
				rc[c[x]] = y;
				rc[c[y]] = x;
				swap(c[x], c[y]);
			}
			if( ch == 'Q' ){
				printf("%d\n", st[r[x]] + c[y] - 1);
			}
		}
	}
	return 0;
} 
