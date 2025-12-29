#include <bits/stdc++.h>

int n;
std::string s;

signed main()
{
	std::freopen("a.in", "r", stdin);
	std::freopen("a.out", "w", stdout);
	
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	
	std::cin >> s; n = s.size(); s = s + " ";
	
	int pos = 0;
	if (s[0] == '0')
	{
		while (s[pos] == '0' && pos <= n) ++pos;
	}
	else
	{
		while (s[pos] == '1' && pos <= n) ++pos;
	}
	
	std::cout << pos << '\n';
	return 0;
}