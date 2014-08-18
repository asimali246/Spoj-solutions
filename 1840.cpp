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

int t, n, m, a[111], i, p[10], ans, flag;
queue<ii> q;

int main(){
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d %d", &n, &m);
		ans = 0, ++m;
		memset(p, 0, sizeof p);
		q = queue<ii>();
		for( i = 1; i <= n; ++i ){
			scanf("%d", &a[i]);
			p[a[i]]++;
			if( i == m )
				q.push(ii(a[i], 1));
			else
				q.push(ii(a[i], 0));
		}
		while( 1 ){
			ii temp = q.front(); q.pop();
			flag = 0;
			for( i = temp.first + 1; i <= 9; ++i )
				if( p[i] ){
					flag = 1;
					break;
				}
			if(flag)
				q.push(ii(temp.first, temp.second));
			else{
				if( temp.second == 1 )
					break;
				++ans;
				p[temp.first]--;
			}
		}
		printf("%d\n", ans + 1);
	}
	return 0;
}
