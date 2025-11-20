#include <bits/stdc++.h>
using namespace std;
int n, l, r, a[2000010], b[2000010];

struct pth {
    int x, y;
    inline int vl() const {
        return a[x] + b[y];
    }
};
inline bool operator < (const pth &a, const pth &b){
    return a.vl() < b.vl();
}

struct info {
    int mna, mnb;//min pos of a and b
    pth ltr; // left-a to right-b min
    pth rtl; // right-a to left-b min
    int fl;//flow min
    int adt;//adtg of flow
    pth rtlnm; // right-a to left-b and not path min flow edge
    int pmna; // split at min flow edge, min a in prefix
    int smnb; // min b in suffix
    inline void upd(int p){
        mna = mnb = p;
        ltr = rtl = pth{p, p};
        fl = adt = 0;
        rtlnm = pth{};
        pmna = p, smnb = {};
    }
    inline void ad(int f){
        adt += f;
        fl += f;
    }
} t[2000010 << 2];
inline int mina(int u, int v){return a[u] < a[v]? u : v;}
inline int minb(int u, int v){return b[u] < b[v]? u : v;}
inline void pu(int k){
    auto &L = t[k << 1], &R = t[k << 1 | 1];
    t[k].mna = mina(L.mna, R.mna);
    t[k].mnb = minb(L.mnb, R.mnb);
    t[k].ltr = min({L.ltr, R.ltr, pth{L.mna, R.mnb}});
    t[k].rtl = min({L.rtl, R.rtl, pth{R.mna, L.mnb}});
    t[k].fl = min(L.fl, R.fl);
    bool lg = L.fl > R.fl, rg = L.fl < R.fl;
    t[k].rtlnm = min({lg? L.rtl : L.rtlnm, rg? R.rtl : R.rtlnm, pth{rg? R.mna : R.pmna, lg? L.mnb : L.smnb}});
    t[k].pmna = lg? mina(L.mna, R.pmna) : L.pmna;
    t[k].smnb = rg? minb(R.mnb, L.smnb) : R.smnb;
    t[k].adt = 0;
}
inline void pd(int k){
    if (t[k].adt){
        t[k << 1].ad(t[k].adt);
        t[k << 1 | 1].ad(t[k].adt);
        t[k].adt = 0;
    }
}
inline pth get(){
    assert(t[1].fl == 0);
    return min(t[1].ltr, t[1].rtlnm);
}
inline void bd(int l = 0, int r = n, int k = 1){
    if (l == r)return t[k].upd(l);
    int M = l + r >> 1;
    bd(l, M, k << 1); bd(M + 1, r, k << 1 | 1);
    pu(k);
}
inline void mdab(int p, int l = 0, int r = n, int k = 1){
    if (l == r)return;
    int M = l + r >> 1; pd(k);
    if (p <= M)mdab(p, l, M, k << 1);
    else mdab(p, M + 1, r, k << 1 | 1);
    pu(k);
}
inline void add(int L, int R, int v, int l = 0, int r = n, int k = 1){
    if (L > R)return;
    if (L <= l && r <= R)return t[k].ad(v);
    int M = l + r >> 1; pd(k);
    if (L <= M)add(L, R, v, l, M, k << 1);
    if (R > M)add(L, R, v, M + 1, r, k << 1 | 1);
    pu(k);
}

constexpr int inf = 1e9 + 10;
void work(){
    cin >> n >> l >> r;
    for (int i = 1; i <= n; ++i)cin >> a[i];
    for (int i = 1; i <= n; ++i)cin >> b[i];
    a[0] = b[0] = inf;
    bd();
    long long rs = 0;
    for (int i = 1; i <= r; ++i){
        auto [x, y] = get();
        rs += a[x] + b[y];
        a[x] = b[y] = inf;
        mdab(x), mdab(y);
        add(min(x, y), max(x, y) - 1, x < y? 1 : -1);
        if (l <= i && i <= r)cout << rs << " ";
    }
    cout << "\n";
}
int main(){
    freopen("summit.in", "r", stdin);
    freopen("summit.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)work();
    return 0;
}