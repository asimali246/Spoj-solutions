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

int n, a[1010], i, k, x, cs=1;
ll ans;

int main(){
	while(1){
		scanf("%d", &n);
		if(n==-1)
			break;
		for(i=1;i<=n+1;++i)
			scanf("%d", &a[i]);
		scanf("%d", &k);
		printf("Case %d:\n", cs++);
		while(k--){
			scanf("%d", &x);
			ans=0;
			for(i=1;i<=n+1;++i)
				ans=(ans*(ll)x)+(ll)a[i];
			printf("%lld\n", ans);
		}
	}
	return 0;
}
