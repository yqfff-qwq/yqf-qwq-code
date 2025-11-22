#include<bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i,l,r) for(int i=l;i<=r;i++)
#define DEP(i,r,l) for(int i=r;i>=l;i--)
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ll long long

void read(){}
template<typename T1,typename ...T2>inline void read(T1 &x,T2 &...oth)
{
    x=0;
    int f=0,ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
        {
            f=1;
        }
        ch=getchar();
    }
    while('0'<=ch&&ch<='9')
    {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    if(f)
    {
        x=-x;
    }
    read(oth...);
}

namespace YZLK{
	const int mod = 998244353;
    const int N = 1e2 + 10;
    int n;
    int a[10] = {0, 2, 3, 6, 7, 8, 9};
    int p[N], len;
    void main() {
		read(n);
        n--;
        len = 0;
        if (n == 0) return puts("0"), void();
        while(n) {
            p[++len] = n % 7;
            n /= 7;
        }
        int sum = 0;
        DEP(i, len, 1)  sum = (sum * 10 + a[p[i]]) % mod;
        cout << sum << "\n";
        return;
    }
}

signed main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);

    int T=1;
    read(T);
    while(T--)
    {
        YZLK::main();
    }

   fclose(stdin);
   fclose(stdout);
    return 0;
}

