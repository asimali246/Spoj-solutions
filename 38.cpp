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
#define INF 2147483647
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;

int tt, r, c, i, j, ans, flag, p, q;
char s[1111][1111], t[1111][1111];
int dx[]={0, 1, 0, -1};
int dy[]={-1, 0, 1, 0};

void floodfill(int x, int y, int d){
    if(x<1 || x>r || y<0 || y>=c)
        return;
    if(s[x][y]!='.')
        return;
    s[x][y]='#';
    if(ans<d)
        ans=d, p=x, q=y;
    for(int j=0;j<4;++j)
        floodfill(x+dy[j], y+dx[j], d+1);
}
int main(){
    scanf("%d", &tt);
    while(tt--){
        scanf("%d %d", &c, &r);
        getchar();
        flag=0;
        for(i=1;i<=r;++i){
            scanf("%s", s[i]);
            for(j=0;j<c;++j){
                if(s[i][j]=='.' && !flag)
                    flag=1, p=i, q=j;
                t[i][j]=s[i][j];
            }
        }
        ans=0;
        floodfill(p, q, 0);
        ans=0;
        for(i=1;i<=r;++i)
            for(j=0;j<c;++j)
                s[i][j]=t[i][j];
        floodfill(p, q, 0);
        printf("Maximum rope length is %d.\n", ans);
    }
    return 0;
}
