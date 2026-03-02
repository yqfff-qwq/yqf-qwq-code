#include <bits/stdc++.h>
#define file_name "ds"
struct prg_timer {
    using csc = std::chrono::steady_clock;const csc::time_point bg;static auto now(){ return csc::now(); } prg_timer() : bg(now()) { }
    void prttm(){ std::clog << "time use = " << std::chrono::duration_cast<std::chrono::milliseconds>(now() - bg).count() << "ms" << std::endl; }
    ~prg_timer(){ prttm(); }
} tmr;
using namespace std;bool SZT_MEM_BG;

int n, q, a[1 << 18 | 1], L;
namespace S1 {
    long long f[1 << 12 | 1][1 << 12 | 1];
    int mmx[1 << 12 << 2 | 3];
    void clr(){
        fill_n(mmx + 1, L << 2, 0);
    }
    void ins(int p, int l = 0, int r = L, int k = 1){
        if (r - l == 1){
            mmx[k] = 1;
            return;
        }
        int M = (l + r) >> 1;
        if (p < M)ins(p, l, M, k << 1);
        else ins(p, M, r, k << 1 | 1);
        int hL = M - l;
        if (mmx[k << 1] == hL || mmx[k << 1 | 1] == hL)mmx[k] = mmx[k << 1] + mmx[k << 1 | 1];
        else mmx[k] = max(mmx[k << 1], mmx[k << 1 | 1]);
    }
    void sol1(){
        for (int l = 1; l <= L; ++l){
            clr();
            for (int r = l; r <= L; ++r){
                ins(a[r]);
                f[l][r] = mmx[1];
            }
        }
        for (int i = 1; i <= L; ++i)
            for (int j = 1; j <= L; ++j)f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
        while (q--){
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;
            cout << f[r1][r2] - f[l1 - 1][r2] - f[r1][l2 - 1] + f[l1 - 1][l2 - 1] << "\n";
        }
        exit(0);
    }
}

vector<tuple<int, int, int, int> > qr;
namespace S2 {
    int mmx[1 << 16 << 2 | 3];
    inline void pu(int k, int hL){
        if (mmx[k << 1] == hL || mmx[k << 1 | 1] == hL)mmx[k] = mmx[k << 1] + mmx[k << 1 | 1];
        else mmx[k] = max(mmx[k << 1], mmx[k << 1 | 1]);
    }
    void ins(int p, int l = 0, int r = L, int k = 1){
        if (r - l == 1){
            mmx[k] = 1;
            return;
        }
        int M = (l + r) >> 1;
        if (p < M)ins(p, l, M, k << 1);
        else ins(p, M, r, k << 1 | 1);
        pu(k, M - l);
    }
    void del(int p, int l = 0, int r = L, int k = 1){
        if (r - l == 1){
            mmx[k] = 0;
            return;
        }
        int M = (l + r) >> 1;
        if (p < M)del(p, l, M, k << 1);
        else del(p, M, r, k << 1 | 1);
        pu(k, M - l);
    }
    struct qry {
        int l, r, id;
    } qu[100010];
    int ct[1 << 16];
    inline void insp(int p){
        if (!ct[a[p]]++)ins(a[p]);
    }
    inline void delp(int p){
        if (!--ct[a[p]])del(a[p]);
    }
    int rs[100010];
    void sol2(){
        int q = qr.size();
        for (int i = 0; i < q; ++i){
            auto [l, _, r, __] = qr[i];
            qu[i] = {l, r, i};
        }
        int S = q / sqrt(L); if (S < 1)S = 1; if (S > L)S = L;
        sort(qu, qu + q, [&](qry u, qry v){
            return u.l / S == v.l / S? u.l / S & 1? u.r < v.r : u.r > v.r : u.l < v.l;
        });
        for (int i = 0, L = 1, R = 0; i < q; ++i){
            while (L > qu[i].l)insp(--L);
            while (R < qu[i].r)insp(++R);
            while (L < qu[i].l)delp(L++);
            while (R > qu[i].r)delp(R--);
            rs[qu[i].id] = mmx[1];
            // clog << i << endl;
        }
        for (int i = 0; i < q; ++i)cout << rs[i] << "\n";
        exit(0);
    }
}

bool SZT_MEM_ED;int main(){
    freopen(file_name".in", "r", stdin);
    freopen(file_name".out", "w", stdout);
    // freopen(file_name"5.in", "r", stdin);
    // freopen(".out", "w", stdout);
    const double static_local_mem_use = fabs(&SZT_MEM_ED - &SZT_MEM_BG) / 1024 / 1024;
    clog << "static local mem use = " << static_local_mem_use << "M" << endl;
    assert(static_local_mem_use < 256);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> q, L = 1 << n;
    for (int i = 1; i <= L; ++i)cin >> a[i];

    if (n <= 12)S1::sol1(); // sam1~4, 1-2 22pts
    bool fl1 = 1;
    while (q--){
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        qr.emplace_back(x, y, l, r);
        fl1 &= x == y && l == r;
    }
    if (n <= 1e5 && fl1)S2::sol2(); // sam5  3  13pts

    return 0;
}
/*
3 7
1 4 2 0 5 7 6 3
2 2 5 5
6 6 7 7
3 3 8 8
1 1 2 2
7 7 8 8
1 1 3 3
1 1 8 8

2
2
3
1
1
1
8
*/
/*
3 1
1 4 2 0 5 7 6 3
1 1 3 3

1
*/