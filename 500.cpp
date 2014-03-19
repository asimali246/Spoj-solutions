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
typedef pair<ll, ll> llp;
typedef pair<double, double> dd;
typedef pair<char, int> ci;

int t, n, cnt[1000010], i, j;

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
class FastOutput {
    public:
        FastOutput() {
            m_dataOffset = 0;
        }
        ~FastOutput() {
        }
        void Flush() {
            if (m_dataOffset) {
                if (write(1, m_data, m_dataOffset));
                m_dataOffset = 0;
            }
        }
        void PrintUint(uint32_t v, char d) {
            if (m_dataOffset + 11 > sizeof(m_data)) Flush();
            if (v < 100000) {
                if (v < 1000) {
                    if (v < 10) {
                        m_data[m_dataOffset + 0] = v + 48;
                        m_dataOffset += 1;
                    } else if (v < 100) {
                        m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
                        m_data[m_dataOffset + 0] = v + 48;
                        m_dataOffset += 2;
                    } else {
                        m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
                        m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
                        m_data[m_dataOffset + 0] = v + 48;
                        m_dataOffset += 3;
                    }
                } else {
                    if (v < 10000) {
                        m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 0] = v + 48;
 
                        m_dataOffset += 4;
 
                    } else {
 
                        m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 0] = v + 48;
 
                        m_dataOffset += 5;
 
                    }
 
                }
 
            } else {
 
                if (v < 100000000) {
 
                    if (v < 1000000) {
 
                        m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 0] = v + 48;
 
                        m_dataOffset += 6;
 
                    } else if (v < 10000000) {
 
                        m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 0] = v + 48;
 
                        m_dataOffset += 7;
 
                    } else {
 
                        m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 0] = v + 48;
 
                        m_dataOffset += 8;
 
                    }
 
                } else {
 
                    if (v < 1000000000) {
 
                        m_data[m_dataOffset + 8] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 0] = v + 48;
 
                        m_dataOffset += 9;
 
                    } else {
 
                        m_data[m_dataOffset + 9] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 8] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
 
                        m_data[m_dataOffset + 0] = v + 48;
 
                        m_dataOffset += 10;
 
                    }
 
                }
 
            }
 
            m_data[m_dataOffset++] = d;
 
        }
 
        void PrintChar(char d) {
 
            if (m_dataOffset + 1 > sizeof(m_data)) Flush();
 
            m_data[m_dataOffset++] = d;
 
        }
 
        void ReplaceChar(int offset, char d) {
 
            m_data[m_dataOffset + offset] = d;
 
        }
 
 
 
    public:
 
        uint8_t m_data[32768];
 
        size_t m_dataOffset;
 
};
inline int inp()
{
    register int noRead=0;
    register char p=getchar_unlocked();
    for(;p<48 || p>57;p=getchar_unlocked());
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    return noRead;
};

int main()
{
    FastInput in;
    FastOutput ou;
    t=in.ReadNext();
    while(t--)
    {
        n=in.ReadNext();
        cnt[n]++;
    }
    for(i=0;i<=1000000;++i)
    {
        for(j=0;j<cnt[i];++j)
            ou.PrintUint(i, '\n');
    }
    ou.Flush();
    return 0;
}
