#include<bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i,l,r) for(int i=l;i<=r;i++)
#define DEP(i,r,l) for(int i=r;i>=l;i--)
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back

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
	const int N = 1e6 + 10;
	char c1[N], c2[N];
	int ne[N];
	int n, m;
    void main() {
		scanf("%s", c1 + 1);
		scanf("%s", c2 + 1);
		n = strlen(c1 + 1);
		m = strlen(c2 + 1);
		for(int i = 2, j = 0;i <= m;i++) {
			while(j and c2[j + 1] != c2[i])	j = ne[j];
			if (c2[j + 1] == c2[i])	j++;
			ne[i] = j;
		}
		for(int i = 1, j = 0;i <= n;i++) {
			while(j and c2[j + 1] != c1[i])	j = ne[j];
			if (c2[j + 1] == c1[i])	        j++;
			if(j == m) {
			    cout << i - m + 1 <<"\n";
			    j = ne[j];
			}
		}
		REP(i, 1, m)	cout << ne[i] << " ";
    return;
  }
}

signed main()
{
    // freopen("XXX.in","r",stdin);
    // freopen("XXX.out","w",stdout);

    int T=1;
    // read(T);
    while(T--)
    {
        YZLK::main();
    }

//    fclose(stdin);
//    fclose(stdout);
    return 0;
}