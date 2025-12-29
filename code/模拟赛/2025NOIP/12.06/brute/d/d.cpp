#include	<iostream>

#include	<cstdio>

#include	<algorithm>

using	std::cin;

using	std::cout;

constexpr	int	N	=	200005;

int	n,	k,	m,	op,	p,	v,	a[N],	ans,	cnt,	tot[N];

signed	main()

{

	freopen("d.in",	"r",	stdin);

	freopen("d.out",	"w",	stdout);

	std::ios::sync_with_stdio(false);

	cin.tie(nullptr);

	cout.tie(nullptr);

	cin	>>	n	>>	k	>>	m;

	for	(int	i	=	1;	i	<=	n;	++i)

		cin	>>	a[i];

	for	(int	i	=	1;	i	<=	m;	++i)

	{

		cin	>>	op;

		if	(op	==	1)

		{

			cin	>>	p	>>	v;

			a[p]	=	v;
		}

		else

		{

			cnt	=	0;

			ans	=	N;

			for	(int	l	=	1,	r	=	1;	l	<=	n;	++l)

			{

				for	(;	r	<=	n	&&	cnt	<	k;	++r)

				{

					cnt	+=	!tot[a[r]];

					++tot[a[r]];
				}

				if	(cnt	==	k)

					ans	=	std::min(ans,	r	-	l);

				--tot[a[l]];

				cnt	-=	!tot[a[l]];
			}

			cout	<<	(ans	==	N	?	-1	:	ans)	<<	'\n';
		}
	}

	return	0;
}