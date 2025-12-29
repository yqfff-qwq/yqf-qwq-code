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
  const int inf = 2e9;
  const int N = 2e5 + 10;
  
  int n, k, m, R;
  int hz[N], a[N << 1], b[N], f[N << 1], mp[N];
  set<int> st[N];
  multiset<int> mn, mx;
  
  struct tree{
    #define ls (u << 1)
    #define rs (u << 1 | 1)
    #define mid ((l + r) >> 1)
    
    int c[N << 2], mi[N << 2], g[N << 2];
    
    int qy(int u, int l, int r, int p){
      if(p <= mi[u]) return l - p + 1;
      if(l == r) return l - mi[u] + 1;
      if(mi[rs] <= p) return min(g[u], qy(rs, mid + 1, r, p));
      else return min(qy(ls, l, mid, min({mi[rs], f[mid + 1], p})), mid + 1 - p + 1);
    }
    
    void push_up(int u, int l, int r){
      g[u] = qy(ls, l, mid, min(mi[rs], f[mid + 1]));
      c[u] = min(c[rs], g[u]);
      mi[u] = min({mi[ls], mi[rs], f[mid + 1]});
      return;
    }
    
    void build(int u, int l, int r){
      if(l == r){
        c[u] = mi[u] = inf;
        return;
      }
      build(ls, l, mid);
      build(rs, mid + 1, r);
      push_up(u, l, r);
      return;
    }
    
    void update(int u, int l, int r, int p){
      if(l == r) return;
      if(p <= mid) update(ls, l, mid, p);
      else update(rs, mid + 1, r, p);
      push_up(u, l, r);
    }
    
    int query(int u, int l, int r, int p, int &v){
      if(p > n) return inf;
      if(l >= p){
        int res = qy(u, l, r, v);
        v = min({v, mi[u], f[l]});
        return res;
      }
      int ans = query(rs, mid + 1, r, p, v);
      if(p <= mid) ans = min(ans, query(ls, l, mid, p, v));
      return ans;
    }
  }tr;
  
  void upd(int id){
    tr.update(1, 1, n, id);
  }
  
  void main(){
    read(n, k, m);
    REP(i, 1, k) mp[i] = -2 * n;
    REP(i, 1, n) read(a[i]);
    REP(i, n + 1, n + k) a[i] = i - n;
    REP(i, 1, n + k){
      f[i] = mp[a[i]];
      mp[a[i]] = i;
      st[a[i]].insert(i);
    }
    REP(i, 1, k){
      mn.insert(*st[i].begin());
      mx.insert(f[*(--st[i].end())]);
    }
    tr.build(1, 1, n);
    while(m--){
      int op;
      read(op);
      if (op == 1) {
        int p, v;
        read(p, v);
        mn.erase(mn.find(*st[a[p]].begin()));
        mx.erase(mx.find(f[*(--st[a[p]].end())]));
        auto it = st[a[p]].find(p);
        ++it;
        int g = *it;
        --it;
        if(it == st[a[p]].begin()){
          f[g] = -2 * n;
          upd(g);
        }
        else{
          --it;
          f[g] = *it;
          upd(g);
        }
        st[a[p]].erase(p);
        mn.insert(*st[a[p]].begin());
        mx.insert(f[*(--st[a[p]].end())]);
        a[p] = v;
        mn.erase(mn.find(*st[a[p]].begin()));
        mx.erase(mx.find(f[*(--st[a[p]].end())]));
        it = st[a[p]].upper_bound(p);
        if(it != st[a[p]].end()){
          f[*it] = p;
          upd(*it);
        }
        if(it != st[a[p]].begin()){
          --it;
          f[p] = *it;
        }
        else    f[p] = -2 * n;
        upd(p);
        st[a[p]].insert(p);
        mn.insert(*st[a[p]].begin());
        mx.insert(f[*(--st[a[p]].end())]);
        continue;
      }
      else {
        R = *(--mn.end());
        int v = *mx.begin();
        int ans = tr.query(1, 1, n, R, v);
        if(ans > n)   puts("-1");
        else          cout << ans << "\n";
        continue;
      }
    }
  }
}

signed main(){
  freopen("d.in", "r", stdin);
  freopen("d.out", "w", stdout);
  
  int T = 1;
  // read(T);
  while(T--){
    YZLK::main();
  }
  
  fclose(stdin);
  fclose(stdout);
  return 0;
}