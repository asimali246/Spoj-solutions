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

char s[1<<14];
int i, ans, l, num, cs = 1;

int main() {
	while( scanf("%s", s) != EOF ) {
		l = (int) strlen(s);
		ans  = num = 0;
		for( i = 0; i < l; ++i ) {
			if( s[i] == '1' && !(ans & 1) )
				++num, ++ans;
			else
			if( s[i] == '0' && (ans & 1))
				++num, ++ans;
		}
		printf("Game #%d: %d\n", cs++, num);
	}
	return 0;
}
