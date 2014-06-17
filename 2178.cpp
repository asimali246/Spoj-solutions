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

int a, d, df[15], i, at[15], c, j;
bool flag;

int main(){
    while(1){
        scanf("%d %d", &a, &d);
        if(!a && !d)
            break;
        for(i=1;i<=a;++i)
            scanf("%d", &at[i]);
        for(i=1;i<=d;++i)
            scanf("%d", &df[i]);
        for(i=1;i<=a;++i){
            c=0;
            for(j=1;j<=d;++j){
                if(df[j]<=at[i])
                    ++c;
            }
            if(c<2)
                break;
        }
        if(i<=a)
            putchar('Y');
        else
            putchar('N');
        putchar('\n');
    }
    return 0;
}
