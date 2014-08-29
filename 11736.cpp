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

int n, i, j, ans, b, e, flag;
bitset<10100> bs;
vi p;

int main() {
	p.clear(), bs.set();
	for( i = 2; i <= 10000; ++i )
		if(bs[i]){
			for( j = i + i; j <= 10000; j += i )
				bs[j] = 0;
			p.push_back(i);
		}
	scanf("%d", &n);
	for( i = 0; i < (int) p.size(); ++i ) {
		b = p[i];
		j = n;
		e = 0;
		while( j != 0 ) 
			e += j/b, j /= b;
		if(!e)
			break;
		if( flag ) 
			printf(" * %d^%d", b, e);
		else
			printf("%d^%d", b, e);
		flag = 1;
	}
	putchar('\n');
	return 0;
}
