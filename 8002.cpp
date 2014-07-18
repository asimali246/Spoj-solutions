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
int t, n, m, a, b, d, i;
ll t1[N], t2[N], c, ans, sum;

void updateT1(int id, ll v){
	while(id<=n)
		t1[id]+=v, id+=id&(-id);
}
void updateT2(int id, ll v){
	while(id<=n)
		t2[id]+=v, id+=id&(-id);
}
ll ReadT1(int id){
	sum=0;
	while(id>0)
		sum+=t1[id], id-=id&(-id);
	return sum;
}
ll ReadT2(int id){
	sum=0;
	while(id>0)
		sum+=t2[id], id-=id&(-id);
	return sum;
}
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		for(i=1;i<=n;++i)
			t1[i]=t2[i]=0;
		while(m--){
			scanf("%d %d %d", &d, &a, &b);
			if(!d){
				scanf("%lld", &c);
				updateT1(a, c);
				updateT1(b+1, -c);
				updateT2(a, c*(a-1));
				updateT2(b+1, -c*b);
			}
			else{
				ans=ReadT1(b)*b-ReadT2(b);
				ans-=ReadT1(a-1)*(a-1)-ReadT2(a-1);
				printf("%lld\n", ans);
			}
		}
	}
	return 0;
}
