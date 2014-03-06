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

int n, m, i, u, v, ver, edg;
vector<vector<ii> > adj;
vi visit;

void dfs(int u)
{
    visit[u]=1;
    ++ver;
    for(int j=0;j<(int)adj[u].size();++j)
    {
        ii temp=adj[u][j];
        if(!visit[temp.first])
            dfs(temp.first);
        ++edg;
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    adj.assign(n+1, vector<ii>());
    visit.assign(n+1, 0);
    for(i=1;i<=n;++i)
        adj[i].clear();
    while(m--)
    {
        scanf("%d %d", &u, &v);
        adj[u].push_back(make_pair(v, 1));
        adj[v].push_back(make_pair(u, 1));
    }
    for(i=1;i<=n;++i)
    {
        edg=0;
        ver=0;
        if(!visit[i])
        {
            dfs(i);
            if(edg/2!=ver-1)
            {
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    return 0;
}
