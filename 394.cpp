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

//MY SECOND DP. VERY HAPPY.
ll dp[5555], i, n;
char s[5555];

int main()
{
    while(1)
    {
        scanf("%s", s);
        if(s[0]=='0')
            break;
        dp[0]=1;
        n=(int)strlen(s);
        dp[1]=1;
        for(i=1;i<n;++i)
        {
            if(s[i]=='0')
            {
                dp[i+1]=dp[i-1];
            }
            else
            {
                dp[i+1]=dp[i];
                if(s[i-1]=='0')
                    continue;
                if(s[i-1]=='1')
                    dp[i+1]+=dp[i-1];
                if(s[i-1]=='2' && s[i]<=54)
                    dp[i+1]+=dp[i-1];
            }
        }
        printf("%lld\n", dp[n]);
    }
    return 0;
}
