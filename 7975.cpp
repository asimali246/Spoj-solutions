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
#define INF 2147483647
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;

int n, a, b, c, cs=1, ta, tb, tc;

int main(){
    while(1){
        scanf("%d", &n);
        if(!n)
            break;
        a=b=c=0;
        --n;
        scanf("%d %d %d", &a, &b, &c);
        scanf("%d %d %d", &ta, &tb, &tc);
        --n;
        c+=b;
        ta+=b, tb+=min(ta, min(b, c)), tc+=min(tb, min(b, c));
        while(n--){
            scanf("%d %d %d", &a, &b, &c);
            a+=min(ta, tb), b+=min(a, min(ta, min(tb, tc))), c+=min(b, min(tb, tc));
            ta=a, tb=b, tc=c;
        }
        printf("%d. %d\n", cs++, tb);
    }
    return 0;
}
