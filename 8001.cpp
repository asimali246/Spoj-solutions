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
#define INF 1000000000
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> llp;
typedef pair<double, double> dd;
typedef pair<char, int> ci;

struct Matrix
{
    ll a[3][3];
};

#define MOD 1000000007
int t, n, m, i, j, k;
ll a, b;

Matrix multiply(Matrix a, Matrix b)
{
    Matrix ans;
    for(i=1;i<=2;++i)
        for(j=1;j<=2;++j)
            for(k=1,ans.a[i][j]=0;k<=2;++k)
                ans.a[i][j]+=(a.a[i][k]*b.a[k][j])%MOD, ans.a[i][j]%=MOD;
    return ans;
}

Matrix solve(Matrix base, int p)
{
    Matrix res;
    for(i=1;i<=2;++i)
        for(j=1;j<=2;++j)
            res.a[i][j]=(i==j);
    while(p)
    {
        if(p&1)
            res=multiply(res, base);
        base=multiply(base, base);
        p>>=1;
    }
    return res;
}
int main()
{
    scanf("%d", &t);
    Matrix ans;
    ans.a[1][1]=ans.a[1][2]=ans.a[2][1]=1;
    ans.a[2][2]=0;
    while(t--)
    {
        scanf("%d %d", &n, &m);
        a=solve(ans, m+2).a[1][2]-1;
        if(a<0)
            a+=MOD;
        a+=MOD;
        b=solve(ans, n+1).a[1][2]-1;
        if(b<0)
            b+=MOD;
        printf("%lld\n", (a-b)%MOD);
    }
    return 0;
}
