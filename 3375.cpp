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

int n, f, a[1010], ans, cs=1, t, i;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &f);
        for(i=1;i<=f;++i)
            scanf("%d", &a[i]);
        sort(a+1, a+f+1);
        reverse(a+1, a+f+1);
        ans=0;
        for(i=1;i<=f;++i){
            if(ans>=n)
                break;
            ans+=a[i];
        }
        printf("Scenario #%d:\n", cs++);
        if(ans>=n)
            printf("%d\n", i-1);
        else
            puts("impossible");
        putchar('\n');
    }
    return 0;
}
