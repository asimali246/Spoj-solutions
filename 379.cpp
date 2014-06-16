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

int n, a[100100], i, flag, b[100100];

int main(){
    while(1){
        scanf("%d", &n);
        if(!n)
            break;
        for(i=1;i<=n;++i)
            scanf("%d", &a[i]), b[a[i]]=i;
        flag=1;
        for(i=1;i<=n;++i)
            if(a[i]!=b[i]){
                flag=0;
                break;
            }
        if(flag)
            puts("ambiguous");
        else
            puts("not ambiguous");
    }
    return 0;
}
