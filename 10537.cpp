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

char s[1111];
int i, l, x, y, a;

int main(){
	while( scanf("%s", s) != EOF ){
		l = (int) strlen(s);
		a = 0;
		x = y = 0;
		for( i = 0; i < l; ++i ) {
			if( a == 0 && s[i] <= 90 )
				++x;
			if( a == 1 && s[i] >= 97 )
				++x;
			if( a == 0 && s[i] >= 97 )
				++y;
			if( a == 1 && s[i] <= 90 )
				++y;
			a = !a;
		}
		printf("%d\n", min(x, y));
	}
	return 0;
}
