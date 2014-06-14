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
#include <stdint.h>
#include <unistd.h>
 
 using namespace std;
 
#define ll long long int
#define INF 1000000000
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1010;
int t, pv[N], le[N], T, pr[N][11], n, i, j, c, x, y, cs=1, fin[N], fout[N], q;
vector<int> g[N];
bool vis[N];
//O(n), O(sqrt(n)) dp algorithm

void dfs(int u){
    fin[u]=++T;
    vis[u]=true;
    for(int j=0;j<(int)g[u].size();++j){
        int v=g[u][j];
        if(!vis[v]){
            pv[v]=u;
            le[v]=le[u]+1;
            dfs(v);
        }
    }
    fout[u]=++T;
}

bool anc(int x, int y){
    return ((fin[x]<=fin[y]) && (fout[y]<=fout[x]));
}
int lca(int x, int y){
    if(anc(x, y))
        return x;
    for(j=10;j>=0;--j)
        if(!anc(pr[x][j], y))
            x=pr[x][j];
    return pv[x];
}
int main(){
    scanf("%d", &t);
    while(t--){
        T=1, pv[1]=1, le[1]=1;
        scanf("%d", &n);
        for(i=1;i<=n;++i)
            g[i].clear(), vis[i]=false;
        for(i=1;i<=n;++i){
            scanf("%d", &c);
            while(c--){
                scanf("%d", &x);
                g[i].push_back(x);
                g[x].push_back(i);
            }
        }
        dfs(1);
        for(i=1;i<=n;++i)
            pr[i][0]=pv[i];
        for(i=1;i<=n;++i)
            for(j=1;j<=10;++j)
                pr[i][j]=pr[pr[i][j-1]][j-1];
        scanf("%d", &q);
        printf("Case %d:\n", cs++);
        while(q--){
            scanf("%d %d", &x, &y);
            if(le[x]>le[y])
                swap(x, y);
            printf("%d\n", lca(x, y));
        }
    }
    return 0;
}
