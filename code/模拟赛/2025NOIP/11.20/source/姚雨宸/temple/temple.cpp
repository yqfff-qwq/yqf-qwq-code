#include <bits/stdc++.h>
//#define int long long
using namespace std;
int n,q,u,v,a[100005],d[100005],f[100005],t[100005];
int H[100005],N[200005],V[200005],l;
void add(int u,int v){N[++l]=H[u];H[u]=l;V[l]=v;}
void dfs(int u,int l)
{
	d[u]=d[l]+1;f[u]=l;
	for(int i=H[u];i;i=N[i])if(V[i]!=l)dfs(V[i],u);
}
bool chk(int u,int v)
{
	for(int i=1;i<=n;i++)t[i]=0;
	if(d[u]<d[v])swap(u,v);
	while(d[u]>d[v]){t[a[u]]++;u=f[u];}
	while(u!=v)
	{
		t[a[u]]++;u=f[u];
		t[a[v]]++;v=f[v];
	}
	t[a[u]]++;
	for(int i=1;i<=n;i++)if(t[i]>=2)return true;return false;
}
signed main()
{
	freopen("temple.in","r",stdin);
	freopen("temple.out","w",stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>q>>q;for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<n;i++){cin>>u>>v;add(u,v);add(v,u);}
    cin>>q;dfs(1,0);
    while(q--){cin>>u>>v;if(chk(u,v))cout<<"Yes\n";else cout<<"No\n";}
    return 0;
}
//TLE 12pts