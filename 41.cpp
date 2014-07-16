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

int t, n, i, id[33], od[33], c, w, e[33], oo, ee, ans;
vi p;
char s[1010], a, b;

void init(){
	for(i=1;i<=26;++i)
		p[i]=i, id[i]=0, od[i]=0, e[i]=0;
	c=26;
}
int findSet(int i){
	return (p[i]==i)?i:p[i]=findSet(p[i]);
}
bool Same(int i, int j){
	return findSet(i)==findSet(j);
}
void Union(int i, int j){
	if(!Same(i, j))
		p[findSet(j)]=p[findSet(i)], --c;
}
int main(){
	scanf("%d", &t);
	p.clear(), p.assign(33, 0);
	while(t--){
		scanf("%d", &n);
		init();
		while(n--){
			scanf("%s", s);
			a=s[0], b=s[(int)strlen(s)-1];
			e[a-'a'+1]=e[b-'a'+1]=1;
			if(a==b)
				continue;
			od[a-'a'+1]++, id[b-'a'+1]++;
			Union(a-'a'+1, b-'a'+1);
		}
		w=0;
		for(i=1;i<=26;++i)
			if(e[i])
				++w;
		if(c!=26-w+1){
			puts("The door cannot be opened.");
			continue;
		}
		if(n==1){
			puts("Ordering is possible.");
			continue;
		}
		oo=ee=0, ans=1;
		for(i=1;i<=26;++i)
			if(e[i]){
				if(id[i]-od[i]==1)
					oo++;
				else
				if(od[i]-id[i]==1)
					ee++;
				else
				if(od[i]!=id[i])
					ans=0;
			}
		if(oo>1 || ee>1)
			ans=0;
		if(!ans)
			puts("The door cannot be opened.");
		else
			puts("Ordering is possible.");
	}
	return 0;
}
