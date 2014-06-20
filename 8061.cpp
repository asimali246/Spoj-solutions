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
#define INF 1000000000
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;

int t, n, k, a[20010], d, i;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        for(i=1;i<=n;++i)
            scanf("%d", &a[i]);
        sort(a+1, a+n+1);
        d=INF;
        --k;
        for(i=1;i+k<=n;++i)
            if(a[i+k]-a[i]<d)
                d=a[i+k]-a[i];
        printf("%d\n", d);
    }
    return 0;
}
