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
 
 using namespace std;
 
#define ll long long int
#define INF 2147483647
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;

int n, s[111], a[1000010], b[1000010], i, j, k, la, lb, x, y;
ll ans;

int main(){
    scanf("%d", &n);
    for(i=1;i<=n;++i)
        scanf("%d", &s[i]);
    la=lb=1;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            for(k=1;k<=n;++k)
                a[la++]=(s[i]*s[j])+s[k];
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            for(k=1;k<=n;++k)
                if(s[i])
                    b[lb++]=s[i]*(s[j]+s[k]);
    sort(a+1, a+la);
    sort(b+1, b+lb);
    i=j=1, --la, --lb;
    while(i<=la && j<=lb){
        if(a[i]<b[j])
            ++i;
        else
        if(a[i]>b[j])
            ++j;
        else{
            x=y=1;
            while(a[i+1]==a[i])
                ++i, ++x;
            while(b[j+1]==b[j])
                ++j, ++y;
            ans+=(x*y);
            ++i, ++j;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
