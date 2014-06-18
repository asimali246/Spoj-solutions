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

int t, i, j;
ll ans, n, k, a, b, den, g;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%lld %lld", &n, &k);
        a=k-1, b=n-k;
        if(a<b)
            swap(a, b);
        ans=1, den=1;
        i=a+1, j=1;
        while(i<=n-1 && j<=b){
            ans*=(ll)i, den*=(ll)j;
            g=gcd(ans, den);
            ans/=g, den/=g;
            ++i, ++j;
        }
        while(i<=n-1)
            ans*=(ll)i++;
        while(j<=b)
            den*=j++;
        ans/=den;
        printf("%lld\n", ans);
    }
    return 0;
}
