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

int t, i;
ll x, y, z, a, d, n;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%lld %lld %lld", &x, &y, &z);
        n=(2*z)/(x+y);
        d=(y-x)/(n-5);
        a=x-2*d;
        printf("%lld\n", n);
        for(i=1;i<=n;++i){
            if(i>1)
                putchar(' ');
            printf("%lld", a);
            a+=d;
        }
        putchar('\n');
    }
    return 0;
}
