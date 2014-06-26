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

int n, id, ff, i, ans, x, j;
map<int, int> mid, mff;
vi f[111];

int main(){
    mid.clear(), mff.clear();
    scanf("%d", &n);
    for(i=1;i<=n;++i)
        f[i].clear();
    for(i=1;i<=n;++i){
        scanf("%d", &id);
        mid[id]=1;
        scanf("%d", &id);
        while(id--){
            scanf("%d", &x);
            f[i].push_back(x);
        }
    }
    for(i=1;i<=n;++i){
        for(j=0;j<(int)f[i].size();++j)
            if(mff.count(f[i][j])==0 && !mid.count(f[i][j]))
                mff[f[i][j]]=1, ++ans;
    }
    printf("%d\n", ans);
    return 0;
}
