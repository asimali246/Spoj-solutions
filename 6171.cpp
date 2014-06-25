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

int t, n, a[2222], i, x;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        memset(a, 0, sizeof a);
        for(i=1;i<=n;++i)
            scanf("%d", &x), a[x+1000]++;
        for(i=0;i<=2001;++i)
            if(a[i]>(n/2)){
                printf("YES ");
                printf("%d\n", i-1000);
                break;
            }
        if(i==2002)
            puts("NO");
    }
    return 0;
}
