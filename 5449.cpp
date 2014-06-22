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

int i, ans, a, b, cs=1, l;
char s[2020];

int main(){
    while(1){
        scanf("%s", s);
        if(s[0]=='-')
            break;
        a=b=ans=0;
        l=(int)strlen(s);
        for(i=0;i<l;++i){
            if(s[i]=='{')
                ++a;
            else{
                if(a)
                    --a;
                else
                    ans++, a++;
            }
        }
        ans+=a/2;
        printf("%d. %d\n", cs++, ans);
    }
    return 0;
}
