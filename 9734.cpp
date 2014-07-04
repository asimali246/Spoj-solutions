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

const int N = 1<<20;
int n, k, c[N], i, v, a[N];
ll ans;
map<int, int> mp;

int main(){
	scanf("%d %d", &n, &k);
	for(i=1;i<=n;++i){
		scanf("%d", &v);
		a[i]=v;
		if(v<N)
			c[v]++;
		else
			mp[v]=1;
	}
	for(i=1;i<=n;++i){
		v=a[i];
		if(v-k>0 && v-k<N && c[v-k])
			ans+=1;
		else
		if(v-k>0 && v-k>N && mp.count(v-k)!=0)
			ans+=1;
	}
	printf("%lld\n", ans);
	return 0;
}
