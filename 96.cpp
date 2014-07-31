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

int h, w, i, j, x, y, d, vis[33][33];
char s[33][33];
priority_queue<pair<int, ii>, vector<pair<int, ii> >, greater<pair<int, ii> > > pq;
int dr[]={-1, 0, 1, 0};
int dc[]={0, 1, 0, -1};

bool valid(int x, int y){
	if(x<1 || x>h || y<1 || y>w)
		return false;
	if(s[x][y]=='X' || vis[x][y])
		return false;
	return true;
}
int main(){
	while(1){
		scanf("%d %d", &w, &h);
		if(!h && !w)
			break;
		pq=priority_queue<pair<int, ii>, vector<pair<int, ii> >, greater<pair<int, ii> > >();
		getchar();
		for(i=1;i<=h;++i){
			for(j=1;j<=w;++j){
				s[i][j]=getchar();
				if(s[i][j]=='S')
					x=i, y=j;
				vis[i][j]=0;
			}
			getchar();
		}
		pq.push(make_pair(0, ii(x, y)));
		while(!pq.empty()){
			pair<int, ii> temp=pq.top();pq.pop();
			d=temp.first;
			x=temp.second.first, y=temp.second.second;
			vis[x][y]=1;
			if(s[x][y]=='D')
				break;
			for(i=0;i<4;++i){
				if(valid(x+dr[i], y+dc[i]))
					pq.push(make_pair(d+s[x+dr[i]][y+dc[i]]-48, ii(x+dr[i], y+dc[i])));
			}
		}
		printf("%d\n", d-20);
	}
	return 0;
}
