#include<bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i,l,r) for(int i=l;i<=r;i++)
#define DEP(i,r,l) for(int i=r;i>=l;i--)
#define MAX(a, b) (a) = max((a), (b))
#define MIN(a, b) (a) = min((a), (b))
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
int id;
namespace YZLK{
    const int N = 2e3 + 10;
    const int inf = 1e18 + 10;
    int n, l, r;
    int a[N], b[N];
    int dp[N][N];
    void main() {
        read(n, l, r);
        REP(i, 1, n)    read(a[i]);
        REP(i, 1, n)    read(b[i]);
        REP(i, 0, n)
            REP(j, 0, n)    dp[i][j] = inf;
        dp[0][0] = 0;
        REP(i, 1, n) {
            DEP(j, i, 1) {
                DEP(k, j, 0) {
                    dp[j][k] = min(dp[j][k], dp[j - 1][k] + a[i]);
                    if (k >= 1) {
                        dp[j][k] = min(dp[j][k], dp[j - 1][k - 1] + a[i] + b[i]);
                        dp[j][k] = min(dp[j][k], dp[j][k - 1] + b[i]);
                    }
                }
            }
        }
        // REP(i, 1, n)
        //     REP(j, 1, i)    cout << dp[i][j] << " \n"[j == i];
        cout << dp[r][r] << "\n"; 
        return ;
    }
}

signed main()
{
    freopen("summit.in","r",stdin);
    freopen("summit.out","w",stdout);

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

/*

code by yqfff_qwq

交代码之前看一下

这是你的代码吗？这是你要交的题吗？

多测了吗？多测清空了吗？多测清空会超时吗？会出现其他问题吗？

数组开小了吗？模数正确吗？调试删干净了吗？

*/