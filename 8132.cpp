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

int n, a[1<<17], i, ans, g;

int main(){
	scanf("%d", &n);
	scanf("%d %d %d", &a[1], &a[2], &a[3]);
	g=gcd(a[2]-a[1], a[3]-a[2]);
	for(i=4;i<=n;++i)
		scanf("%d", &a[i]), g=gcd(g, a[i]-a[i-1]);
	ans=(a[n]-a[1])/g+1;
	printf("%d\n", ans-n);
	return 0;
}
