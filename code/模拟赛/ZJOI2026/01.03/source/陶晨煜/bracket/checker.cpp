#include "testlib.h"
#define MAXN 100

int a[MAXN], deg[MAXN];

int main(int argc, char *argv[])
{
	registerTestlibCmd(argc, argv);
	int n = inf.readInt();
	for (int i = 0; i < n; i++)
		a[i] = inf.readInt();
	std::string s = ouf.readToken("[()]+");
	if (s.length() != n)
		quitf(_wa, "Expect %d characters in a line", n);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(')
		{
			++sum;
			++deg[i];
			++deg[a[i] - 1];
		}
		else
		{
			--sum;
			if (sum < 0)
				quitf(_wa, "Invalid bracket sequence");
		}
	}
	if (sum != 0)
		quitf(_wa, "Invalid bracket sequence");
	for (int i = 0; i < n; i++)
		if (deg[i] != 1)
			quitf(_wa, "Expect degree 1 for node %d, got %d", i + 1, deg[i]);
	quitf(_ok, "OK");
	return 0;
}
