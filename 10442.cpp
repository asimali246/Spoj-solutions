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

const int N = 1<<17;
int n, p[N], c[N], i;
ll ans;

int main(){
	while(1){
		scanf("%d", &n);
		if(!n)
			break;
		for(i=1;i<=n;++i)
			scanf("%d", &c[i]);
		for(i=1;i<=n;++i)
			scanf("%d", &p[i]);
		sort(p+1, p+n+1);
		sort(c+1, c+n+1);
		reverse(p+1, p+n+1);
		ans=0;
		for(i=1;i<=n;++i)
			ans+=(ll)c[i]*(ll)p[i];
		printf("%lld\n", ans);
	}
	return 0;
}
