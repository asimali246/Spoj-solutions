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

int t, co, n, m, a, b, c, i, ans;
vector<pair<int, ii> > e;
vi p;

void init(){
	for(i=1;i<=n;++i)
		p[i]=i;
}
int findSet(int i){
	return (p[i]==i)?i:p[i]=findSet(p[i]);
}
bool same(int x, int y){
	return findSet(x)==findSet(y);
}
void Union(int i, int j){
	p[findSet(j)]=p[findSet(i)];
}

int main(){
	p.clear(), p.assign(1010, 0);
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &co, &n, &m);
		e.clear();
		while(m--){
			scanf("%d %d %d", &a, &b, &c);
			e.push_back(make_pair(c, ii(a, b)));
		}	
		ans=0;
		init();
		sort(e.begin(), e.end());
		for(i=0;i<(int)e.size();++i){
			pair<int, ii> temp=e[i];
			if(!same(temp.second.first, temp.second.second))
				Union(temp.second.first, temp.second.second), ans+=co*temp.first;
		}
		printf("%d\n", ans);
	}
	return 0;
}
