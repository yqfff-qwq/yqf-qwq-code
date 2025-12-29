#include "testlib_for_lemons.h"
#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
	registerLemonChecker(argc, argv);
	int fullScore = atoi(argv[4]);
	int n = inf.readInt(), t = inf.readInt();
	std::vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		a[i] = inf.readInt();
		b[i] = inf.readInt();
	}
	std::string p = ans.readString();
	std::string q = ouf.readString();
	if (p != q) {
		quitf(_wa, "Wrong Answer. Found %s, but excepted %s.", q.c_str(), p.c_str());
	}
	if (p == "no") {
		quitf(_ok, "Correct Answer!");
	}
	std::vector<int> c(n);
	for (int i = 0; i < n; i++)
		c[i] = ouf.readInt();
	for (int i = 0; i < n; i++) {
		if (c[i] < a[i] || c[i] + t > b[i]) {
			quitp(fullScore * 0.6, "60% Points, wrong construction. The %d-th photo is taken from the %d-th moment onwards, but the time is illegal.", i + 1, c[i]);
		}
	}
	std::sort(c.begin(), c.end());
	for (int i = 0; i < n - 1; i++) {
		if (c[i + 1] - c[i] < t) {
			quitp(fullScore * 0.6, "60% Points, wrong construction. There exists a time when two photos are being taken simultaneously.");
		}
	}
	quitf(_ok, "Correct Answer!");
	return 0;
}
