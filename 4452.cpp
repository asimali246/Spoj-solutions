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
 
int t, flag, num, sign;
char s[1<<20], *p, ch;
ll ans;

int main()
{
    scanf("%d", &t);
    getchar();
    while(t--)
    {
        getchar();
        gets(s);
        flag=0;
        sign=0;
        for(p=strtok(s, " ");p;p=strtok(NULL, " "))
        {
            if(!sign)
                num=atoi(p);
            if(!flag)
                flag=1, ans=(ll)num, sign=1;
            else
            {
                if(sign)
                {
                    sign=0;
                    ch=p[0];
                }
                else
                {
                    sign=1;
                    if(ch=='*')
                        ans*=(ll)num;
                    if(ch=='/')
                        ans/=(ll)num;
                    if(ch=='+')
                        ans+=(ll)num;
                    if(ch=='-')
                        ans-=(ll)num;
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
