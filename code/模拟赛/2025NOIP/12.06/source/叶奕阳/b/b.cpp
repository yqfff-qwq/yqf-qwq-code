#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define RAP(i,a)      for(auto i=(a).begin();i!=(a).end();i++)
#define REP(i,a,b)    for(int i=(a);i<=(b);i++)
#define DEP(i,a,b)    for(int i=(a);i>=(b);i--)
#define REPc(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define DEPc(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
#define ADD(a,b) (a)=((a)+(b))%mod
#define SUB(a,b) (a)=((a)-(b)+mod)%mod
#define MUL(a,b) (a)=(((a)%mod)*((b)%mod))%mod
#define MAX(a,b) (a)=max((a),(b))
#define MIN(a,b) (a)=min((a),(b))
#define ALL(a)   (a).begin(),(a).end()
#define SZ(a)    ((int)a.size())
#define ppc(x)   __builtin_popcount(x)
#define DBG(x)   cerr<<#x<<' '<<(x)<<'\n'
#define int long long
using namespace std;
typedef pair<int,int> pii;

namespace Yyydrasil {

    const int N = 3e5 + 5;
    int n, a[N], ch[N], b[N], m, mv[N], s[N], ans;
    set<int> numb;

    int getmn() { int res = *begin(numb); numb.erase(res); return res; }
    int getmx() { int res = *--end(numb); numb.erase(res); return res; }

    void main() {
        cin >> n;
        REP(i, 1, n) cin >> a[i];
        REP(i, 1, n) ch[i] = (a[i] < a[i + 1] ? '<' : '>'); ch[n] = '#';
        REP(i, 1, n) cin >> b[i], numb.insert(b[i]);
        REP(i, 1, n) {
            if (i == 1) {
                if (ch[i] == '<') s[i] = getmn();
                if (ch[i] == '>') s[i] = getmx();
                mv[++m] = 1;
            } else {
                if (ch[i - 1] != ch[i]) {
                    if (ch[i - 1] == '<') s[i] = getmx();
                    if (ch[i - 1] == '>') s[i] = getmn();
                    if (ch[i - 1] != ch[1]) mv[++m] = i;
                }
            }
        }
        int s1 = s[mv[m]];
        DEP(i, m, 2) s[mv[i]] = s[mv[i - 1]]; s[1] = s1;
        REP(i, 1, n) {
            if (!s[i]) {
                if (ch[i] == '<') s[i] = getmn();
                else              s[i] = getmx();
            }
        }
        REP(i, 1, n - 1) {
            ans += abs(s[i + 1] - s[i]);
        }
        cout << ans << '\n';
        REP(i, 1, n) cout << s[i] << ' ';
        cout << '\n';
    }
}

signed main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
