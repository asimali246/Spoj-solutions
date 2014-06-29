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

int t, ans, c, l, len;
char s[20*101000], *p;

int main(){
    scanf("%d", &t);
    getchar();
    while(t--){
        gets(s);
        if(strlen(s)==0){
            t++;
            continue;
        }
        ans=0;
        c=l=0;
        for(p=strtok(s, " \t\r");p;p=strtok(NULL, " \t\r")){
            len=(int)strlen(p);
            if(len==l)
                ++c;
            else
                ans=max(ans, c), c=1, l=len;
        }
        ans=max(ans, c);
        printf("%d\n", ans);
    }
    return 0;
}
