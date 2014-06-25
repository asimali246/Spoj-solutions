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
int la, lb, a[N], b[N], i, sa[N], sb[N], j, msa, msb, ans;

int main(){
    while(1){
        scanf("%d", &la);
        msa=msb=ans=0;
        if(!la)
            break;
        for(i=1;i<=la;++i)
            scanf("%d", &a[i]), sa[i]=a[i], sa[i]+=sa[i-1];
        scanf("%d", &lb);
        for(i=1;i<=lb;++i)
            scanf("%d", &b[i]), sb[i]=b[i], sb[i]+=sb[i-1];
        i=1, j=1;
        while(i<=la && j<=lb){
            if(a[i]<b[j])
                msa+=a[i++];
            else
            if(a[i]>b[j])
                msb+=b[j++];
            else
            if(a[i]==b[j]){
                ans+=max(msa, msb);
                msa=msb=0;
                ans+=a[i];
                ++i, ++j;
            }
        }
        while(i<=la)
            msa+=a[i++];
        while(j<=lb)
            msb+=b[j++];
        ans+=max(msa, msb);
        printf("%d\n", ans);
    }
    return 0;
}
