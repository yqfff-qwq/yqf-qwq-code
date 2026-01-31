#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
const int MAXM = 30;

int T, N;
int A[MAXN];
int SA[MAXN], RA[MAXN], RB[MAXN], TEMP[MAXN];

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar(); }
    return x * f;
}

void rsort(int n, int *sa, int *ra, int *rb, int *temp, int m) {
    for (int i = 0; i <= m; i++) TEMP[i] = 0;
    for (int i = 1; i <= n; i++) TEMP[ra[rb[i]]]++;
    for (int i = 1; i <= m; i++) TEMP[i] += TEMP[i - 1];
    for (int i = n; i >= 1; i--) sa[TEMP[ra[rb[i]]]--] = rb[i];
}

int main() {
    freopen("starlight.in", "r", stdin);
    freopen("starlight.out", "w", stdout);

    T = read();
    while (T--) {
        N = read();
        for (int i = 1; i <= N; i++) A[i] = read();

        long long ans = 0;
        bool chk = true;

        for (int b = MAXM; b >= 0 && chk; b--) {
            int mask = (1 << (b + 1)) - 1;
            int mask_b = (1 << b);
            
            for (int i = 1; i <= N; i++) RB[i] = i;
            for (int i = 1; i <= N; i++) RA[i] = (A[i] & mask);

            rsort(N, SA, RA, RB, TEMP, mask);

            int p = 1;
            while (p <= N) {
                int l = p;
                while (p <= N && (A[SA[p]] & mask) == (A[SA[l]] & mask)) p++;
                
                int cnt_l = 0, cnt_r = 0;
                for (int k = l; k < p; k++) {
                    if (A[SA[k]] & mask_b) cnt_r++;
                    else cnt_l++;
                }

                if (cnt_l > 0 && cnt_r > 0) {
                    chk = false;
                    break;
                }
            }
        }

        if (chk) {
            sort(A + 1, A + N + 1);
            int j = 1;
            for (int i = 1; i < N; i++) {
                while (j <= N && A[j] < A[i]) j++;
                if (j > i) j = i + 1;
                while (j <= N && A[j] == A[i]) j++;
                if (j <= N) ans += (N - j + 1);
            }
        }

        printf("%lld\n", ans);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}