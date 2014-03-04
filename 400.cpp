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
 
 using namespace std;
 
#define ll long long int
#define INF 2147483647
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> llp;
typedef pair<double, double> dd;
typedef pair<char, int> ci;

char ans[33][33];
char s[222];
int i, n, flag, x, y, j;

int main()
{
    while(1)
    {
        scanf("%d", &n);
        if(!n)
            break;
        scanf("%s", s);
        x=y=1;
        flag=1;
        for(i=0;i<(int)strlen(s);++i)
        {
            if(flag && y==n+1)
                flag=0, y=n, ++x;
            else
            if(!flag && y==0)
                flag=1, y=1, ++x;
            ans[x][y]=s[i];
            if(flag)
                ++y;
            else
                --y;
        }
        for(i=1;i<=n;++i)
            for(j=1;j<=x;++j)
                putchar(ans[j][i]);
        putchar('\n');
    }
    return 0;
}
