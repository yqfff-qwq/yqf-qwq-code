#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char** argv){
	if (argc < 4)throw invalid_argument("Too few arguments.");
	ifstream in(argv[1]), out(argv[2]), ans(argv[3]);
	auto rds = [](ifstream &ifs){
		string s;
		ifs >> s;
		if (!ifs)throw runtime_error("Can not read string.");
		return s;
	};
	string fi = rds(out), fia = rds(ans);
	if (fi != fia)throw runtime_error("Expect " + fia + ", Read " + fi);
	if (fi == "yes"){
		static int tm[10010];
		auto rdi = [](ifstream &ifs){
			int x;
			ifs >> x;
			if (!ifs)throw runtime_error("Can not read int.");
			return x;
		};
		int n = rdi(in); if (n < 0 || n > 1e4)throw runtime_error("Bad input.");
		for (int i = 1; i <= n; ++i)tm[i] = rdi(out);
		int t = rdi(in);
		static int a[10010], b[10010];
		for (int i = 1; i <= n; ++i)a[i] = rdi(in), b[i] = rdi(in);
		auto CK = [&](bool c){
			if (!c){
				cout << "PA0.6" << endl;
				exit(0);
			}
		};
		for (int i = 1; i <= n; ++i)CK(a[i] <= tm[i] && tm[i] + t <= b[i]);
		vector<pair<int, int> > sec;
		for (int i = 1; i <= n; ++i)sec.emplace_back(tm[i], tm[i] + t);
		sort(sec.begin(), sec.end());
		for (int i = 1; i < n; ++i)CK(sec[i - 1].second <= sec[i].first);
	}
	cout << "OK" << endl;
	return 0;
}