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

int i, l, h, p, m;
double x, a[555], ans;

int bin(double v){
    l=1, h=i;
    while(l<=h){
        m=(l+h)>>1;
        if(a[m]>=v)
            h=m-1, p=m;
        if(a[m]<v)
            l=m+1;
    }
    return p;
}
int main(){
    ans=0.0;
    for(i=1;;++i){
        ans+=(double)(1.0/(i+1));
        a[i]=ans;
        if(a[i]>=5.20)
            break;
    }
    while(1){
        scanf("%lf", &x);
        if(x==0.0)
            break;
        printf("%d card(s)\n", bin(x));
    }
    return 0;
}
