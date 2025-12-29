#include <bits/stdc++.h>

int n;
std::string s;

signed main()
{
//	std::freopen("a.in", "r", stdin);
//	std::freopen("a.out", "w", stdout);
	
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	
	std::cin >> s; n = s.size();
	
	int pos = 0, cnt = 0;
	
	if (s[0] == '1')
	{
		while (s[pos] == '1' && pos < n) ++pos;
		
		for (int i = 0; i < s.size(); ++i)
			cnt += s[i] == '0';
		
		std::cout << std::abs(cnt - pos) << '\n';
	}
	else
	{
		while (s[pos] == '0' && pos < n) ++pos;
		
		for (int i = 0; i < s.size(); ++i)
			cnt += s[i] == '1';
		
		std::cout << std::abs(cnt - pos) << '\n';
	}
	
	return 0;
}