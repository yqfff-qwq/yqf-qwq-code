#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int T, n, ans;
int a[N];
inline int read()
{
    int res = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
        res = (res << 3) + (res << 1) + (c ^ 48), c = getchar();
    return res;
}
signed main()
{
    freopen("starlight.in", "r", stdin);
    freopen("starlight.out", "w", stdout);
    cin >> T;
    while (T--)
    {
        ans = 0;
        n = read();
        for (int i = 1; i <= n; i++)
            a[i] = read();
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                bool flag = 1;
                for (int x = 1; x <= 1000; x++)
                {
                    if (!flag)
                        break;
                    for (int k = 1; k <= n; k++)
                    {
                        if (((a[k] ^ x) <= (a[i] ^ x)) || ((a[k] ^ x) >= (a[j] ^ x)))
                            continue;
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}