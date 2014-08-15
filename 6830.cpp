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

int t, i, x, y;
char a[5], b[5];
map<string, int> mp;

int main(){
	scanf("%d", &t);
	getchar();
	while( t-- ) {
		mp.clear();
		for( i = 1; i <= 16; ++i ) {
			scanf("%s %s %d %d", a, b, &x, &y);
			getchar();
			if( mp.count(a) == 0 )
				mp[a] = 1;
			if( mp.count(b) == 0 )
				mp[b] = 1;
			if( x > y )
				mp[b] = 0;
			else
				mp[a] = 0;
		}
		map<string, int>::iterator it = mp.begin();
		while( it != mp.end() ){
			if( it->second == 1 ){
				printf("%s\n", it->first.c_str());
				break;
			}
			++it;
		}
	}
	return 0;
}
