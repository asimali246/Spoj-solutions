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

const int N = 1<<11;
int a, b, c, d, n, t, i, j;
char s[10];
int tree[N][N], v;

inline void updatey(int x, int y, int v){
	while(y<=n){
		tree[x][y]+=v;
		y+=(y&(-y));
	}
}
void update(int x, int y, int v){
	while(x<=n){
		updatey(x, y, v);
		x+=(x&(-x));
	}
}
inline int queryy(int x, int y){
	int sum=0;
	while(y>0){
		sum+=tree[x][y];
		y-=(y&(-y));
	}
	return sum;
}
int query(int x, int y){
	int sum=0;
	while(x>0){
		sum+=queryy(x, y);
		x-=(x&(-x));
	}
	return sum;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i=1;i<=n;++i)
			for(j=1;j<=n;++j)
				tree[i][j]=0;
		while(1){
			scanf("%s", s);
			if(s[0]=='E')
				break;
			if(s[1]=='E'){
				scanf("%d %d %d", &a, &b, &v);
				++a, ++b;
				d=query(a, b)-query(a-1, b)-query(a, b-1)+query(a-1, b-1);
				update(a, b, -d);
				update(a, b, v);
			}
			if(s[1]=='U'){
				scanf("%d %d %d %d", &a, &b, &c, &d), ++c, ++d, ++a, ++b;
				printf("%d\n", query(c, d)-query(a-1, d)-query(c, b-1)+query(a-1, b-1));
			}
		}
		putchar('\n');
	}
	return 0;
}
