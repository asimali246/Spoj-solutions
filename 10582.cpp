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

const int N = 1000010;
int n, a[N], i, k, v, flag;
priority_queue<int> pq;
map<int, int> mp;
bool s=false;

int main(){
	scanf("%d", &n);
	for(i=1;i<=n;++i)
		scanf("%d", &a[i]), mp[i]=0;
	scanf("%d", &k);
	for(i=1;i<=k;++i)
		pq.push(a[i]);
	for(i=k;i<=n;++i){
		flag=1;
		while(flag){
			v=pq.top();
			if(mp[v]){
				mp[v]--;
				pq.pop();
			}
			else
				flag=0;
		}
		pq.push(a[i+1]);
		if(s)
			putchar(' ');
		s=true;
		printf("%d", v);
		mp[a[i+1-k]]++;
	}
	putchar('\n');
	return 0;
}
