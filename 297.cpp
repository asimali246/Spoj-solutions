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

int t, n, c, a[100100], l, h, m, ans, i, p, co;

bool check(int x){
    p=a[1], co=1;
    for(i=2;i<=n;++i){
        if(a[i]-p>=x)
            p=a[i], co++;
        if(co==c)
            return true;
    }
    return false;
}
int solve(){
    l=1, h=a[n];
    while(l<=h){
        m=(l+h)>>1;
        if(check(m))
            ans=m, l=m+1;
        else
            h=m-1;
    }
    return ans;
}
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &c);
        for(i=1;i<=n;++i)
            scanf("%d", &a[i]);
        sort(a+1, a+n+1);
        printf("%d\n", solve());
    }
    return 0;
}
