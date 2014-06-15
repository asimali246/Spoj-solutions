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

const int N = 10010;
int t, n, x, y, c, k, i, j, pv[N], de[N], dist[N], fin[N], fout[N], T, z, pr[N][15], tnd;
vector<ii> g[N];
bool was[N], flag;
char s[1111];

void dfs(int u){
    was[u]=true;
    fin[u]=++T;
    for(int j=0;j<(int)g[u].size();++j){
        ii v=g[u][j];
        if(!was[v.first]){
            pv[v.first]=u;
            de[v.first]=de[u]+1;
            dist[v.first]=dist[u]+v.second;
            dfs(v.first);
        }
    }
    fout[u]=++T;
}

bool anc(int x, int y){
    return (fin[x]<=fin[y] && fout[y]<=fout[x]);
}
int lca(int x, int y){
    if(anc(x, y))
        return x;
    for(j=14;j>=0;--j)
        if(!anc(pr[x][j], y))
            x=pr[x][j];
    return pv[x];
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i=1;i<=n;++i)
            g[i].clear(), was[i]=false;
        pv[1]=1, de[1]=0, dist[1]=0, T=0;
        for(i=1;i<=n-1;++i){
            scanf("%d %d %d", &x, &y, &c);
            g[x].push_back(ii(y, c));
            g[y].push_back(ii(x, c));
        }
        getchar();
        dfs(1);
        for(i=1;i<=n;++i)
            pr[i][0]=pv[i];
        for(i=1;i<=n;++i)
            for(j=1;j<=14;++j)
                pr[i][j]=pr[pr[i][j-1]][j-1];
        while(1){
            gets(s);
            if(strcmp(s, "DONE")==0)
                break;
            if(s[0]=='D'){
                sscanf(s, "DIST %d %d", &x, &y);
                if(de[x]>de[y])
                    swap(x, y);
                z=lca(x, y);
                printf("%d\n", dist[x]+dist[y]-2*dist[z]);
            }
            else{
                sscanf(s, "KTH %d %d %d", &x, &y, &k);
                flag=false;
                if(de[x]>de[y])
                    swap(x, y), flag=true;
                z=lca(x, y);
                tnd=de[x]+de[y]-2*de[z]+1;
                if(flag)
                    swap(x, y);
                if(k<=de[x]-de[z]){
                    for(i=1;i<k;++i)
                        x=pv[x];
                    printf("%d\n", x);
                }
                else{
                    for(i=1;i<=tnd-k;++i)
                        y=pv[y];
                    printf("%d\n", y);
                }
            }
        }
        putchar('\n');
    }
    return 0;
}
