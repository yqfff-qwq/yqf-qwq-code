#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

int main() {
	for (int t = 0; t < 10; t++) {
		std::string name = "root" + std::to_string(t);
		std::string op = "std.exe < " + name + ".in > " + name + ".out";
		system(op.c_str());
	}

  return 0;
}
