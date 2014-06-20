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

int m, b[1001000], i, j;
char P[1001000], c;
bool flag=false;

void kmpPreProcess(){
    i=0, j=-1;
    b[i]=j;
    while(i<m){
        while(j>=0 && P[i]!=P[j])j=b[j];
        ++i;
        ++j;
        b[i]=j;
    }
}
void kmpsearch(){
    kmpPreProcess();
    i=0, j=0;
    c=getchar();
    while(c!='\n'){
        while(j>=0 && c!=P[j])j=b[j];
        ++i;
        ++j;
        if(j==m){
            printf("%d\n", i-j);
            j=b[j];
        }
        c=getchar();
    }
}
int main(){
    while(scanf("%d", &m)!=EOF){
        scanf("%s", P);
        getchar();
        if(flag)
            putchar('\n');
        flag=true;
        kmpsearch();
    }
    return 0;
}
