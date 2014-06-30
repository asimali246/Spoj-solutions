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

int tt, n, k, t, f;
ll ans;
int main(){
	scanf("%d", &tt);
	while(tt--){
		scanf("%d %d %d %d", &n, &k, &t, &f);
		ans=((ll)k*(ll)f-(ll)n)/((ll)k-1);
		printf("%lld\n", ans);
	}
	return 0;
}
