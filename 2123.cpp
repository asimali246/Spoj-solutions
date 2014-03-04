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

int n, ans, i, sum;
int a[10010];

int main()
{
    while(1)
    {
        scanf("%d", &n);
        if(n==-1)
            break;
        sum=0;
        for(i=1;i<=n;++i)
            scanf("%d", &a[i]), sum+=a[i];
        ans=0;
        if(sum%n)
            printf("-1\n");
        else
        {
            sum/=n;
            for(i=1;i<=n;++i)
                ans+=abs(a[i]-sum);
            printf("%d\n", ans/2);
        }
    }
    return 0;
}
