#include <iostream>
using namespace std;
int T;
long long x, y;
int main()
{
    freopen("berry.in", "r", stdin);
    freopen("berry.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> x >> y;
        if (abs(x - y) > 1)
            cout << "Yes"
                 << "\n";
        else
            cout << "No"
                 << "\n";
    }
    return 0;
}
