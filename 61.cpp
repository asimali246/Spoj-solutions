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
#define EPS 1e-15

template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}

typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 30100;
struct Node{
	int a, b;
}t[N*5];

int tt=10, cs=1, n, i, m, k;
char s[N];

void build(int id, int l, int r){
	if(l==r){
		if(s[l]=='(')
			t[id].a=0, t[id].b=1;
		else
			t[id].a=1, t[id].b=0;
		return;
	}
	int m=(l+r)>>1;
	build(id*2, l, m);
	build(id*2+1, m+1, r);
	int a, b, c, d;
	a=t[id*2].a, b=t[id*2].b;
	c=t[id*2+1].a, d=t[id*2+1].b;
	if(b>c)
		t[id].a=a, t[id].b=b-c+d;
	if(b<c)
		t[id].a=a+c-b, t[id].b=d;
	if(b==c)
		t[id].a=a, t[id].b=d;
}
void update(int id, int l, int r, int p){
	if(l==r && l==p){
		if(t[id].a==1)
			t[id].a=0, t[id].b=1;
		else
			t[id].a=1, t[id].b=0;
		return;
	}
	int m=(l+r)>>1;
	if(p<=m)
		update(id*2, l, m, p);
	else
		update(id*2+1, m+1, r, p);
	int a, b, c, d;
	a=t[id*2].a, b=t[id*2].b;
	c=t[id*2+1].a, d=t[id*2+1].b;
	if(b>c)
		t[id].a=a, t[id].b=b-c+d;
	if(b<c)
		t[id].a=a+c-b, t[id].b=d;
	if(b==c)
		t[id].a=a, t[id].b=d;
}
int main(){
	while(tt--){
		scanf("%d", &n);
		getchar();
		for(i=1;i<=n;++i)
			s[i]=getchar();
		getchar();
		build(1, 1, n);
		printf("Test %d:\n", cs++);
		scanf("%d", &m);
		getchar();
		while(m--){
			scanf("%d", &k);
			getchar();
			if(!k){
				if(t[1].a==0 && t[1].b==0)
					puts("YES");
				else
					puts("NO");
			}
			else
				update(1, 1, n, k);
		}
	}
	return 0;
}
