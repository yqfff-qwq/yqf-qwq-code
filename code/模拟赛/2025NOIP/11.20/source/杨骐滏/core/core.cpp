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
    int n, m, k;
    char s[N], t[N];
    void main() {
        read(n, m, k);
        scanf("%s", s + 1);
        scanf("%s", t + 1);

        return ;
    }
}

signed main()
{
    freopen("core.in","r",stdin);
    freopen("core.out","w",stdout);

    int T=1;
    read(id);
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