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

char s[111], i, a, b, l, p;

int main(){
    while(scanf("%s", s)!=EOF){
        l=(int)strlen(s);
        a=b=p=0;
        for(i=0;i<l;++i)
            if(i==l-1 && (s[i]=='_'))
                a=b=1;
            else
            if(i==0 && (s[i]=='_' || isupper(s[i])))
                a=b=1;
            if(s[i]=='_' && p)
                a=b=1;
            else
            if(s[i]=='_')
                a=1, p=1;
            else
            if(isupper(s[i]))
                b=1, p=0;
            else
                p=0;
        if(a && b)
            puts("Error!");
        else{
            if(a){
                for(i=0;i<l;++i)
                    if(s[i]=='_')
                        s[i+1]=toupper(s[i+1]);
                    else
                        putchar(s[i]);
            }
            if(b){
                for(i=0;i<l;++i){
                    if(isupper(s[i]))
                        putchar('_'), putchar(tolower(s[i]));
                    else
                        putchar(s[i]);
                }
            }
            if(!a && !b){
                for(i=0;i<l;++i)
                    putchar(s[i]);
            }
            putchar('\n');
        }
    }
    return 0;
}
