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

int t, n, a[11111], p, l, h, m, d, i;

void bin(){
    l=1, h=i;
    while(l<=h){
        m=(l+h)>>1;
        if(a[m]>=n)
            h=m-1, p=m;
        if(a[m]<n)
            l=m+1;
    }
}
int main(){
    for(i=1;;++i){
        a[i]=a[i-1]+i;
        if(a[i]>10000000)
            break;
    }
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        bin();
        d=n-a[p-1];
        if(p%2)
            d=p-d+1;
        printf("TERM %d is %d/%d\n", n, d, (p-d+1));
    }
    return 0;
}
