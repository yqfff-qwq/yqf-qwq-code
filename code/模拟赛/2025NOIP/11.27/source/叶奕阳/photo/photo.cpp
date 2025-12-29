#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
#define REP(i,a,b)    for(int i=(a);i<=(b);i++)
#define DEP(i,a,b)    for(int i=(a);i>=(b);i--)
#define REPc(i,a,b,c) for(int i=(a);i<=(b);i+=c)
#define DEPc(i,a,b,c) for(int i=(a);i>=(b);i-=c)
#define MAX(a,b) (a)=max((a),(b))
#define MIN(a,b) (a)=min((a),(b))
#define MOD(a)   ((a)%mod+mod)%mod
#define ADD(a,b) (a)=((a)+(b))%mod
#define SUB(a,b) (a)=MOD((a)-(b))
#define MUL(a,b) (a)=MOD((a)*(b))
#define SZ(a)    ((int)(a).size())
#define ALL(a)   (a).begin(),(a).end()
#define ppc(a)   __builtin_popcountll(a)
#define ctz(a)   __builtin_ctz(a)
#define DBG(a)     cerr<<#a<<": "<<a<<endl
#define AST(a,l,r) assert(a>=l),assert(a<=r)
#define int long long
using namespace std;
typedef pair<int,int> pii;

namespace Yyydrasil {

    const int inf = 0x3f3f3f3f3f3f3f3f;
    const int N = 1e4 + 5;
    struct P { int l, r, id; } a[N];
    int n, t, ans[N];

    priority_queue<pii, vector<pii>, greater<pii>> que;

    void dfs(int step, int tim) {
        if (step == n + 1) {
            cout << "yes\n";
            REP(i, 1, n) cout << ans[i] << ' ';
            cout << '\n';
            exit(0);
        } else {
            REP(i, 1, n) if (ans[a[i].id] == -1 && tim + t > a[i].r) return;
            REP(i, 1, n) {
                if (ans[a[i].id] == -1) {
                    ans[a[i].id] = max(a[i].l, tim);
                    dfs(step + 1, ans[a[i].id] + t);
                    ans[a[i].id] = -1;
                }
            }
        }
    }

    void main() {
        cin >> n >> t;
        REP(i, 1, n) cin >> a[i].l >> a[i].r, a[i].id = i;
        a[n + 1].l = inf;
        sort(a + 1, a + 1 + n, [](P a, P b) { return a.l < b.l; });
        if (t == 1) {
            REP(i, 1, n) {
                que.push({a[i].r, i});
                REP(j, a[i].l, a[i + 1].l - 1) {
                    int id = que.top().second; que.pop();
                    if (j < a[id].r) {
                        ans[a[id].id] = j;
                    } else {
                        cout << "no\n";
                        exit(0);
                    }
                    if (que.empty()) break;
                }
            }
            cout << "yes\n";
            REP(i, 1, n) cout << ans[i] << ' ';
            cout << '\n';
        } else {
            REP(i, 1, n) ans[i] = -1;
            dfs(1, 0);
            cout << "no\n";
        }
    }
}

signed main() {
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
