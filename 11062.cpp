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

int n, q, i, x, flag, ans;
int a[100010];

void binar(int val)
{
    int low=1, high=n;
    while(low<=high)
    {
        int center=(low+high)>>1;
        if(a[center]>val)
            high=center-1;
        else
        if(a[center]<val)
            low=center+1;
        else
        if(a[center]==val)
            high=center-1, flag=1, ans=center;
    }
}
int main()
{
    scanf("%d %d", &n, &q);
    for(i=1;i<=n;++i)
        scanf("%d", &a[i]);
    while(q--)
    {
        scanf("%d", &x);
        flag=0;
        binar(x);
        if(flag)
            printf("%d\n", ans-1);
        else
            printf("-1\n");
    }
    return 0;
}
