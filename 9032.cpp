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
int t, n, cs=1, i, j, ans[N], pos[N];
ll v;

int main(){
	for(i=2;i<=101;++i){
		for(j=i*i*i;j<N;j+=(i*i*i))
			ans[j]=1;
	}
	n=1;
	for(i=1;i<N;++i)
		if(!ans[i])
			pos[i]=n++;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("Case %d: ", cs++);
		if(!ans[n])
			printf("%d\n", pos[n]);
		else
			printf("Not Cube Free\n");
	}
	return 0;
}
