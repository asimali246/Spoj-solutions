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

int t, s, cc, i, a[111], c[111], pos, p, flag;

int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d %d", &s, &cc);
		for( i = 1; i <= s; ++i )
			scanf("%d", &a[i]), c[i] = 0;
		pos = s;
		p = a[s];
		while(1){
			for( i = 1; i < pos; ++i )
				c[i] = a[i + 1] - a[i];
			pos--;
			flag = 0;
			for( i = 1; i <= pos; ++i )
				if( c[i] != c[1] )
					flag=1;
			if(!flag)
				break; 
			for( i = 1; i <= pos; ++i )
				a[i] = c[i];
		}
		flag = 0;
		while(cc--) {
			for( i = pos+1; i < s; ++i )
				c[i] += c[i-1];
			p = c[s-1] + p;
			if(flag)
				putchar(' ');
			flag=1;
			printf("%d", p);
		}
		putchar('\n');
		flag=0;
	}
	return 0;
}
