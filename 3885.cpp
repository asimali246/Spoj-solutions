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
int k, l, m, i, a[N], n;

int main(){
	scanf("%d %d %d", &k, &l, &m);
	a[1]=1;
	for(i=2;i<=1000000;++i){
		if(a[i-1]==0)
			a[i]=1;
		else
		if((i-k>=1 && a[i-k]==0) || i-k==0)
			a[i]=1;
		else
		if((i-l>=1 && a[i-l]==0) || i-l==0)
			a[i]=1;
		else
			a[i]=0;
	}
	while(m--){
		scanf("%d", &n);
		if(a[n])
			putchar('A');
		else
			putchar('B');
	}
	putchar('\n');
	return 0;
}
