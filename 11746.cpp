#include <cstdio>
using namespace std;
double a[10001];
int t;
long long i;
int main()
{
    a[0]=0.0;
    for(i=1;i<=10000;++i)
        a[i]=a[i-1]+(double)i/(double)(i*i*i*i+i*i+1);
    scanf("%d", &t);
    while(t--){scanf("%lld", &i);printf("%.5lf\n", a[i]);}
}
