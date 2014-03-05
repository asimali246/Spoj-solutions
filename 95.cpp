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

int n, x, num, tmp;
stack<int> st;

int main()
{
    while(1)
    {
        scanf("%d", &n);
        if(!n)
            break;
        tmp=n;
        num=1;
        st=stack<int>();
        while(tmp--)
        {
            scanf("%d", &x);
            st.push(x);
            while(1)
            {
                if(st.top()==num)
                    st.pop(), ++num;
                else
                    break;
                if(st.empty())
                    break;
            }
        }
        if(num==n+1)
            printf("yes\n");
        else
            puts("no");
    }
    return 0;
}
