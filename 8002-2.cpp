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
int tt, n, m, p, q, i, d;
ll t[5*N], c, lazy[5*N];
void update(int, int, int, int, int, ll);

void update(int id, int l, int r, int a, int b, ll v){
	if(l==a && r==b){
		t[id]+=(ll)(r-l+1)*v;
		lazy[id]+=v;
		return;
	}
	int m=(l+r)>>1;
	t[id*2]+=lazy[id]*(ll)(m-l+1);
	t[id*2+1]+=lazy[id]*(ll)(r-m);
	lazy[id*2]+=lazy[id];
	lazy[id*2+1]+=lazy[id];
	lazy[id]=0;
	if(b<=m)
		update(id*2, l, m, a, b, v);
	else
	if(a>m)
		update(id*2+1, m+1, r, a, b, v);
	else
		update(id*2, l, m, a, m, v), update(id*2+1, m+1, r, m+1, b, v);
	t[id]=t[id*2]+t[id*2+1];
}
ll query(int id, int l, int r, int a, int b){
	if(l==a && r==b){
		return t[id];
	}
	int m=(l+r)>>1;
	t[id*2]+=lazy[id]*(ll)(m-l+1);
	t[id*2+1]+=lazy[id]*(ll)(r-m);
	lazy[id*2]+=lazy[id];
	lazy[id*2+1]+=lazy[id];
	lazy[id]=0;
	if(b<=m)
		return query(id*2, l, m, a, b);
	else
	if(a>m)
		return query(id*2+1, m+1, r, a, b);
	else
		return query(id*2, l, m, a, m)+query(id*2+1, m+1, r, m+1, b);
}
int main(){
	scanf("%d", &tt);
	while(tt--){
		scanf("%d %d", &n, &m);
		for(i=1;i<5*N;++i)
			t[i]=lazy[i]=0;
		while(m--){
			scanf("%d %d %d", &d, &p, &q);
			if(!d){
				scanf("%lld", &c);
				update(1, 1, n, p, q, c);
			}
			else
				printf("%lld\n", query(1, 1, n, p, q));
		}
	}
	return 0;
}
