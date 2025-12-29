#include	<iostream>

#include	<cstdio>

#include	<algorithm>

#include	<set>

using	std::cin;

using	std::cout;

constexpr	int	N	=	1003;

int	n;

long	long	s[N],	ans	=	1e18;

std::set<long	long>	f;

signed	main()

{

	freopen("a.in",	"r",	stdin);

	freopen("a.out",	"w",	stdout);

	std::ios::sync_with_stdio(false);

	cin.tie(nullptr);

	cout.tie(nullptr);

	cin	>>	n;

	for	(int	i	=	1;	i	<=	n;	++i)

	{

		cin	>>	s[i];

		s[i]	+=	s[i	-	1];
	}

	f.insert(s[1]);

	for	(int	i	=	2;	i	<=	n;	++i)

	{

		for	(int	j	=	i;	j	<=	n;	++j)

		{

			long	long	v	=	s[j]	-	s[i	-	1];

			auto	p	=	f.upper_bound(v);

			if	(p	!=	f.end())

				ans	=	std::min(ans,	*p	-	v);

			if	(p	!=	f.begin())

			{

				--p;

				ans	=	std::min(ans,	v	-	*p);
			}
		}

		for	(int	j	=	1;	j	<=	i;	++j)

			f.insert(s[i]	-	s[j	-	1]);
	}

	cout	<<	ans;

	return	0;
}