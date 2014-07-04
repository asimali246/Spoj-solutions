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

class FastInput {
	public:
		FastInput() {
			m_dataOffset = 0;
			m_dataSize = 0;
			m_v = 0x80000000;
		}
		uint32_t ReadNext() {
			if (m_dataOffset == m_dataSize) {
				int r = read(0, m_buffer, sizeof(m_buffer));
				if (r <= 0) return m_v;
				m_dataOffset = 0;
				m_dataSize = 0;
				int i = 0;
				if (m_buffer[0] < '0') {
					if (m_v != 0x80000000) {
						m_data[m_dataSize++] = m_v;
						m_v = 0x80000000;
					}
					for (; (i < r) && (m_buffer[i] < '0'); ++i);
				}
				for (; i < r;) {
					if (m_buffer[i] >= '0') {
						m_v = m_v * 10 + m_buffer[i] - 48;
						++i;
					} else {
						m_data[m_dataSize++] = m_v;
						m_v = 0x80000000;
						for (i = i + 1; (i < r) && (m_buffer[i] < '0'); ++i);
					}
				}
			}
			return m_data[m_dataOffset++];
		}
	public:
		uint8_t m_buffer[32768];
		uint32_t m_data[16384];
		size_t m_dataOffset, m_dataSize;
		uint32_t m_v;
};

FastInput in;
const int N = 100010;
int n, a[N], i, sum[N];
ll ans;
stack<int> st;

int main(){
	while(1){
		n=in.ReadNext();
		if(!n)
			break;
		for(i=1;i<=n;++i)
			a[i]=in.ReadNext();
		st=stack<int>();
		//Calculating left indices
		for(i=1;i<=n;++i){
			while(!st.empty()){
				if(a[i]<=a[st.top()])
					st.pop();
				else
					break;
			}
			if(st.empty())
				sum[i]=i-1;
			else
				sum[i]=i-st.top()-1;
			st.push(i);
		}
		//Calculating right indices
		st=stack<int>();
		for(i=n;i>=1;--i){
			while(!st.empty()){
				if(a[i]<=a[st.top()])
					st.pop();
				else
					break;
			}
			if(!st.empty())
				sum[i]+=st.top()-i-1;
			else
				sum[i]+=n-i;
			st.push(i);
		}
		ans=0;
		for(i=1;i<=n;++i)
			ans=max(ans, (ll)a[i]*(ll)(sum[i]+1));
		printf("%lld\n", ans);
	}
	return 0;
}
