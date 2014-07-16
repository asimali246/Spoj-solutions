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

int t, m, n, i, j, x, y, a[1010], b[1010];
ll ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &m, &n);
		for(i=1;i<=m-1;++i)
			scanf("%d", &a[i]);
		for(i=1;i<=n-1;++i)
			scanf("%d", &b[i]);
		sort(a+1, a+m), reverse(a+1, a+m);
		sort(b+1, b+n), reverse(b+1, b+n);
		i=j=1, x=y=1, ans=0;
		while(i<=m && j<=n){
			if(i==m){
				while(j<n)
					ans+=(ll)b[j++]*x;
				break;
			}
			if(j==n){
				while(i<m)
					ans+=(ll)a[i++]*y;
				break;
			}
			if(a[i]>b[j]){
				ans+=(ll)(a[i]*y);
				++i;
				++x;
			}
			else{
				ans+=(ll)(b[j]*x);
				++j;
				++y;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
