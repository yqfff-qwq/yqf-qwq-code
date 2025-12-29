/*
g++ easy.cpp -o easy -std=c++14 -Wall -pedantic -O2
*/

#include <bits/stdc++.h>
using namespace std;

constexpr unsigned M = 998244353;

struct mod {
	unsigned x;
	mod() = default;
	mod(int x) : x((x % M + M) % M) { }
	mod(int x, bool) : x(x) { }
	mod& operator += (mod o){
		x += o.x;
		if (x >= M)x -= M;
		return *this;
	}
	mod& operator -= (mod o){
		x -= o.x;
		if (x >> 31)x += M;
		return *this;
	}
};

inline mod operator + (mod a, mod b){
	a.x += b.x;
	if (a.x >= M)a.x -= M;
	return a;
}
inline mod operator - (mod a, mod b){
	a.x -= b.x;
	if (a.x >> 31)a.x += M;
	return a;
}
inline mod operator * (mod a, mod b){
	a.x = 1ull * a.x * b.x % M;
	return a;
}
ostream &operator << (ostream &a, mod b){
	return a << b.x;
}

int n, k, a[200010];
int gcd(int x, int y){
	return __gcd(x, y);
}
template <typename... Args>
	int gcd(int fi, int se, Args... arg){
		return gcd(gcd(fi, se), arg...);
	}
namespace S1 {
	void sol1(){
		cout << mod(1 + k / gcd(a[1], a[2], k)) << "\n";
	}
}
namespace S2 {
	int mnl[15][1010]; // mnl_{r,v} ~ r -> v
	mod f[15];
	void sol2(){
		for (int r = 1; r <= n; ++r){
			fill_n(mnl[r], k, 0);
			mnl[r][a[r]] = r;
			int t = gcd(a[r], k);
			for (int l = r - 1; l; --l){
				t = gcd(a[l], t);
				for (int x = 0; x < k; ++x)if (x % t == 0)
					if (!mnl[r][x])mnl[r][x] = l;
			}
		}
		fill_n(f, n + 1, mod());
		f[0] = 1;
		for (int i = 0; i < n; ++i)
			for (int v = 0; v < k; ++v)
				for (int r = i + 1; r <= n; ++r){
					if (mnl[r][v] > i){
						f[r] += f[i];
						break;
					}
				}
		cout << accumulate(f + 1, f + n + 1, mod()) << "\n";
	}
}
namespace S3 {
	mod f[200010];
	void sol3(){
		fill_n(f, n + 1, mod());
		f[0] = 1;
		for (int i = 0; i < n; ++i){
			f[i + 1] += f[i];
			if (i + 2 <= n)f[i + 2] += f[i] * (k - 1);
		}
		cout << accumulate(f + 1, f + n + 1, mod()) << "\n";
	}
}
namespace S4 {
	int gd[20][200010];
	inline int gt(int l, int r){
		assert(l < r);
		int t = __lg(r - l + 1);
		return gcd(gd[t][l], gd[t][r - (1 << t) + 1]);
	}
	template <typename _Func_>
		vector<tuple<int, int, int> > spl(int l, int r, _Func_ &&f){
			vector<tuple<int, int, int> > V;
			while (l <= r){
				int v = f(l);
				int L = l, R = r, rr = -1;
				while (L <= R){
					int M = (L + R) >> 1;
					if (f(M) == v)rr = M, L = M + 1;
					else R = M - 1;
				}
				assert(rr != -1);
				V.emplace_back(l, rr, v);
				l = rr + 1;
			}
			reverse(V.begin(), V.end());
			return V;
		}

	// mnl_{i,a_i}=i
	vector<pair<int, int> > Vr[200010];
		// (p,v) in Vr_r : mnl_{r,u*v} <- max (p)

	int mnl[1010][1010];
	int mxmnl[1010];
	int mxx[1010];

	vector<int> F;//factor of k
	int mxp[10010];

	inline void tmx(int &x, int y){
		if (x < y)x = y;
	}

	mod f[200010], s[200010];
	void sol4(){
		for (int i = 1; i <= n; ++i)gd[0][i] = gcd(a[i], k);
		for (int i = 1; 1 << i <= n; ++i)
			for (int j = 1; j + (1 << i) - 1 <= n; ++j)
				gd[i][j] = gcd(gd[i - 1][j], gd[i - 1][j + (1 << (i - 1))]);
		for (int r = 1; r <= n; ++r){
			Vr[r].clear();
			auto &V = Vr[r];
			for (auto lrv : spl(1, r - 1, [&](int u){return gt(u, r);})){
				int r = get<1>(lrv), v = get<2>(lrv);
				V.emplace_back(r, v);
			}
		}

		F.clear();
		for (int i = 1; i * i <= k; ++i){
			if (k % i == 0){
				F.emplace_back(i);
				if (i * i < k)F.emplace_back(k / i);
			}
		}
		sort(F.begin(), F.end());
		auto fnd = [&](int v){
			return lower_bound(F.begin(), F.end(), v) - F.begin();
		};
		int LL = F.size();

		{
			for (int i = 1; i <= n; ++i)fill_n(mnl[i], k, 0);
			for (int r = 1; r <= n; ++r){
				mnl[r][a[r]] = r;
				for (auto pv : Vr[r]){
					int p = get<0>(pv), v = get<1>(pv);
					for (int u = 0; u * v < k; ++u)if (!mnl[r][u * v])mnl[r][u * v] = p;
				}
			}
			fill_n(mxmnl, k, 0);
			fill_n(mxx, k, 0);
		}

		fill_n(f, n + 1, mod());
		f[0] = 1;
		s[1] = 1;
		fill_n(mxp, LL + 1, 0);

		for (int r = 1; r <= n; ++r){
			int c = 0;
			for (auto pv : Vr[r]){
				int p = get<0>(pv), v = get<1>(pv);
				f[r] += (k / v - c) * s[p];
				c = k / v;
			}
			f[r] += s[r];
			int bt = 0;
			for (auto pv : Vr[r]){
				int p = get<0>(pv), v = get<1>(pv);
				if (a[r] % v == 0){
					f[r] -= s[p];
					bt = p;
					break;
				}
			}
			for (int v = 0; v < k; ++v)f[r] -= s[max(mxx[v], mxmnl[v])];
			//for (auto pv : Vr[r]){
			//	int p = get<0>(pv), v = get<1>(pv);
			//	tmx(mxp[lower_bound(F.begin(), F.end(), v) - F.begin()], p);
			//}
			tmx(mxx[a[r]], r);
			for (auto pv : Vr[r]){
				int p = get<0>(pv), v = get<1>(pv);
				for (int s = fnd(v); s <= LL; ++s)tmx(mxp[s], p);
				for (int u = 0; u * v < k; ++u)tmx(mxmnl[u * v], p);
			}
			//for (int i = 0; i < k; ++i){
			//	clog << i << ":" << mxmnl[i] << "," << mxp[fnd(gcd(i, k))] << endl;
			//	assert(mxmnl[i] == mxp[fnd(gcd(i, k))]);
			//}
			s[r + 1] = s[r] + f[r];
		}
		cout << s[n + 1] - 1 << "\n";
	}
}
int sn = 0;
void work(){
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	if (n == 2)return S1::sol1(); // 10pts
	if ((sn += n) <= 9 && k <= 1000)return S2::sol2(); // 30pts
	if ([&]{
		for (int i = 1; i < n; ++i)if (gcd(a[i], a[i + 1]) != 1)return 0;
		return 1;
	}())return S3::sol3();// 20pts
	return S4::sol4();
}
int main(){
	freopen("easy.in", "r", stdin);
	freopen("easy.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)work();
	return 0;
}
/*
1
9 573
563 150 195 558 485 404 185 436 409

531714534
*/
