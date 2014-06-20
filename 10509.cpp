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

int a[1000010], i, d, n, t;

int main(){
    a[1]=2;
    d=5;
    for(i=2;i<=1000000;++i)
        a[i]=(a[i-1]+d)%1000007, d+=3, d%=1000007;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%d\n", a[n]);
    }
    return 0;
}
