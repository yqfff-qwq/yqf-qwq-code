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
    const int N = 2e5 + 10;
    int n, q, c;
    int a[N];
    struct node{
        int l, r, x;
    }qy[N];
    void main() {
        read(n, q, c);
        REP(i, 1, n)    read(a[i]);
        REP(i, 1, q) {
            read(qy[i].l, qy[i].r, qy[i].x);
        }
        REP(i, 1, q) {
            int sum = abs(a[qy[i].l] - qy[i].x);
            REP(j, qy[i].l + 1, qy[i].r) {
                sum = abs(a[j] - sum);
            }
            cout << sum << "\n";
        }
        return ;
    }
}

signed main()
{
    freopen("reflection.in","r",stdin);
    freopen("reflection.out","w",stdout);

    int T=1;
    // read(T);
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