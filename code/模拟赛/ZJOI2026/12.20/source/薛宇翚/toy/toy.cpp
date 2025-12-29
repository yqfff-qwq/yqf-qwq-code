#include <bits/stdc++.h>
using namespace std;
const int N=3e6+100;
int b,a,n,s[N];
char c[N];
long long as;
int main()
{
	freopen("toy.in","r",stdin);
	freopen("toy.out","w",stdout);
	scanf("%d%d%d%s",&b,&a,&n,c+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+(c[i]^'0');
	}
	as=n-a;
	int le=1,ri=b;
	while(ri<n)
	{
		int nex=min(n,le+a-1);
		if(s[ri]==s[nex])
		{
			printf("IMPOSSIBLE\n");
			return 0;
		}
		while(s[ri]<s[nex])
		{
			ri++;
		}
		int bant=s[ri]-b+1;
		while(s[le]<bant)
		{
			le++;
		}
		as+=b;
	}
	printf("%lld\n",as);
	return 0;
}
