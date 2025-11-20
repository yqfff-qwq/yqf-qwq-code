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
	mt19937 rd(time(0));
	const int N = 1e6 + 10;
	const int inf = 1e9;
	int f[N];
	int n, q;
	int find(int x) {
		return (f[x] == x ? f[x] : f[x] = find(f[x]));
	}
	struct node{
		int l, r, x;
	}qy[N];
	vector<int> ql[N], qr[N];
	struct tree{
		struct FHQ {
			int fa, ls, rs, key, sz, val, t1, t2;
		}tr[N];
		int idx, rt, T1, T2, T3;
		int build(int u, int v) {
			tr[u] = {0, 0, 0, (int)rd(), 1, v, 0, 0};
			return u;
		}
		void push_up(int u) {
			tr[u].sz = tr[tr[u].ls].sz + tr[tr[u].rs].sz + 1;
			tr[tr[u].ls].fa = tr[tr[u].rs].fa = u;
			return;
		}
		void flip(int u) {
			if (!u)	return;
			tr[u].t1 ^= 1;
			tr[u].t2 = -tr[u].t2;
			tr[u].val = -tr[u].val;
			swap(tr[u].ls, tr[u].rs);
		}
		void upd(int u, int v) {
			if (!u)	return;
			tr[u].val += v;
			tr[u].t2 += v;
			return;
		}
		void push_down(int u) {
			if (tr[u].t1) {
				flip(tr[u].ls);
				flip(tr[u].rs);
				tr[u].t1 = 0;
			}
			if (tr[u].t2) {
				upd(tr[u].ls, tr[u].t2);
				upd(tr[u].rs, tr[u].t2);
				tr[u].t2 = 0;
			}
			return;
 		}
		void split(int u, int k, int &x, int &y) {
			if (u == 0)	{x = y = 0;return;}
			push_down(u);
			if (tr[u].val <= k){
				x = u;
				split(tr[u].rs, k, tr[u].rs, y);
			}
			else {
				y = u;
				split(tr[u].ls, k, x, tr[u].ls);
			}
			push_up(u);
			return;
		}
		int merge(int u, int v) {
			if (!u or !v)	return u + v;
			push_down(u);
			push_down(v);
			if (tr[u].val == tr[v].val)	f[find(u)] = find(v);
			if (tr[u].key > tr[v].key) {
				tr[u].rs = merge(tr[u].rs, v);
				push_up(u);
				return u;
			}
			else {
				tr[v].ls = merge(u, tr[v].ls);
				push_up(v);
				return v;
			}
		}
		int query(int u) {
			vector<int> ve;
			for(int i = u;i;i = tr[i].fa)	ve.pb(i);
			reverse(ve.begin(), ve.end());
			for(auto it:ve)	push_down(it);
			return tr[u].val;
		}
		void solve(int v) {
			upd(rt, -v);
			split(rt, 0, T1, T2);
			flip(T1);
			rt = merge(T1, T2);
			tr[rt].fa = 0;
		}
		void insert(int u, int x) {
			rt = merge(rt, build(u, x));
			tr[rt].fa = 0;
			return;
		}
	}tr;
	int a[N];
	int ans[N];
    void main() {
		read(n, q);
		REP(i, 1, n)	read(a[i]);
		REP(i, 1, q) {
			read(qy[i].l, qy[i].r, qy[i].x);
			ql[qy[i].l].pb(i);
			qr[qy[i].r].pb(i);
			f[i] = i;
		}
		REP(i, 1, n) {
			for(auto v:ql[i]) {
				tr.insert(v, qy[v].x);
			}
			tr.solve(a[i]);
			for(auto v:qr[i]) {
				ans[v] = tr.query(find(v));
			}
		}
		REP(i, 1, q)	cout << ans[i] << "\n";
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

/*

code by yqfff_qwq

交代码之前看一下

这是你的代码吗？这是你要交的题吗？

多测了吗？多测清空了吗？多测清空会超时吗？会出现其他问题吗？

数组开小了吗？模数正确吗？调试删干净了吗？

*/
