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

const int N = 4010;
int n, a[N], b[N], c[N], d[N], i, j, x[N*N], y[N*N], lx, ly;
ll p, q, ans;

int main(){
    scanf("%d", &n);
    for(i=1;i<=n;++i)
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    lx=ly=1;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            x[lx++]=a[i]+b[j];
    sort(x+1, x+lx);
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            y[ly++]=c[i]+d[j];
    sort(y+1, y+ly);
    reverse(y+1, y+ly);
    i=j=1, --lx, --ly;
    while(i<=lx && j<=ly){
        if(x[i]==-y[j]){
            p=q=1;
            while(i+1<=lx && x[i+1]==-y[j])
                ++i, ++p;
            while(j+1<=ly && x[i]==-y[j+1])
                ++j, ++q;
            ans+=p*q;
            ++i, ++j;
        }
        else
        if(x[i]>-y[j])
            ++j;
        else
            ++i;
    }
    printf("%lld\n", ans);
    return 0;
}
