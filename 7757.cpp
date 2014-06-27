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

char s[2222], *p, c;
int flag, ans;

int main(){
    while(1){
        gets(s);
        if(s[0]=='*')
            break;
        flag=1;
        ans=0;
        for(p=strtok(s, " ");p;p=strtok(NULL, " "))
            if(!ans)
                ans=1, c=p[0];
            else{
                if(tolower(p[0])!=tolower(c))
                    flag=0;
            } 
        if(flag)
            puts("Y");
        else
            puts("N");
    }
    return 0;
}
