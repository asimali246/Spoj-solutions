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

const int N = 20100;
int n, m, i, ans[N];
char s[22];
map<string, int> mp;

int main() {
	while(1){
		scanf("%d %d", &n, &m);
		if( !n && !m )
			break;
		for( i = 1; i <= n; ++i )
			ans[i] = 0;
		mp.clear();
		for( i = 1; i <= n; ++i ){
			scanf("%s", s);
			if( mp.count(s) == 0 )
				mp[s] = 1;
			else
				mp[s]++;
			ans[mp[s]]++;
			ans[mp[s] - 1]--;
		}
		for( i = 1; i <= n; ++i )
			printf("%d\n", ans[i]);
	}
	return 0;
}
