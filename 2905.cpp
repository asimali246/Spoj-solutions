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

const int N = 1000010;
int n, i, c[N], x, j, a[2222];
ll ans;

int main(){
	while(1){
		scanf("%d", &n);
		if(!n)
			break;
		for(i=1;i<N;++i)
			c[i]=0;
		for(i=1;i<=n;++i)
			scanf("%d", &x), a[i]=x, c[x]++;
		for(i=1;i<N-2;++i)
			c[i]+=c[i-1];
		ans=0;
		for(i=1;i<=n;++i)
			for(j=i+1;j<=n;++j)
				if(a[i]+a[j]<N-9)
					ans+=(ll)(c[N-5]-c[a[i]+a[j]]);
		printf("%lld\n", ans);
	}
	return 0;
}
