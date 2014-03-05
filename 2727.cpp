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

int t, p, q, l, m, x, i;
vi a, b;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &l, &m);
        a.clear();
        b.clear();
        for(i=1;i<=l;++i)
            scanf("%d", &x), a.push_back(x);
        for(i=1;i<=m;++i)
            scanf("%d", &x), b.push_back(x);
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        p=q=0;
        while(1)
        {
            if(a[p]<b[q])
                ++p;
            else
            if(a[p]>b[q])
                ++q;
            else
            if(a[p]==b[q])
                ++q;
            if(p==l || q==m)
                break;
        }
        if(p==l)
            puts("MechaGodzilla");
        else
            puts("Godzilla");
    }
    return 0;
}
