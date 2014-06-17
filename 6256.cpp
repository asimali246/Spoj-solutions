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

int t, i, n;
int a[200010], b[200010];
ll ans;

void merge(int l, int m, int h){
    int i=l, j=m+1, c=1;
    while(i<=m && j<=h){
        if(a[i]<=a[j])
            b[c++]=a[i], ++i;
        else
            b[c++]=a[j], ans+=(ll)(m-i+1), ++j;
    }
    while(i<=m)
        b[c++]=a[i++];
    while(j<=h)
        b[c++]=a[j++];
    for(i=l;i<=h;++i)
        a[i]=b[i-l+1];
}
void merge_sort(int l, int h){
    if(l<h){
        int m=(l+h)>>1;
        merge_sort(l, m);
        merge_sort(m+1, h);
        merge(l, m, h);
    }
}
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i=1;i<=n;++i)
            scanf("%d", &a[i]);
        ans=0;
        merge_sort(1, n);
        printf("%lld\n", ans);
    }
    return 0;
}
