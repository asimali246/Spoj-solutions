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

int t, flag, i, mach=0, pos=0, a[4];
char s[111], *p;

int main()
{
    scanf("%d", &t);
    getchar();
    while(t--)
    {
        getchar();
        gets(s);
        flag=1;
        pos=0;
        a[0]=a[1]=a[2]=-99;
        for(p=strtok(s, " ");p;p=strtok(NULL, " "))
        {
            if(flag)
            {
                mach=0;
                for(i=0;p[i];++i)
                    if(p[i]=='m')
                        mach=1;
                if(!mach)
                    a[pos++]=atoi(p);
                else 
                    pos++;                   
                flag=0;
            }
            else
                flag=1;
        }
        if(a[0]!=-99)
            printf("%d + ", a[0]);
        else
            printf("%d + ", a[2]-a[1]);
        if(a[1]!=-99)
            printf("%d = ", a[1]);
        else
            printf("%d = ", a[2]-a[0]);
        if(a[2]!=-99)
            printf("%d\n", a[2]);
        else
            printf("%d\n", a[0]+a[1]);
    }
    return 0;
}
