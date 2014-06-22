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

char a[1010], b[1010], x[150], i, l, y[150], j;

int main(){
    while(scanf("%s", a)!=EOF){
        scanf("%s", b);
        l=(int)strlen(a);
        for(i=97;i<=122;++i)
            x[i]=y[i]=0;
        for(i=0;i<l;++i)
            x[a[i]]++;
        l=(int)strlen(b);
        for(i=0;i<l;++i)
            y[b[i]]++;
        for(i=97;i<=122;++i)
            for(j=0;j<min(x[i], y[i]);++j)
                putchar(i);
        putchar('\n');
    }
    return 0;
}
