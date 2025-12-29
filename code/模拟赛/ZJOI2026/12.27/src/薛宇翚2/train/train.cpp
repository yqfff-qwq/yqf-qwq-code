#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+100;
int n;
char s[N];
ll pre[N],suf[N],prec[N],sufc[N];
int findre(int l,int r,int cur)
{
	while(l<r)
	{
		int mi=(l+r+1)>>1;
		if(sufc[mi]>=cur)
		{
			l=mi;
		}
		else
		{
			r=mi-1;
		}
	}
	return l;
}
int findle(int l,int r,int cur)
{
	while(l<r)
	{
		int mi=(l+r)>>1;
		if(prec[mi]>=cur)
		{
			r=mi;
		}
		else
		{
			l=mi+1;
		}
	}
	return l;
}
int main()
{
	freopen("train.in","r",stdin);
	freopen("train.out","w",stdout);
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='O')
		{
			printf("0 ");
			continue;
		}
		int j=i;
		while(j<=n&&s[j]!='O')
		{
			j++;
		}
		i--;
		//cout<<i<<" "<<j<<"\n";
		pre[i]=prec[i]=0;
		for(int k=i+1;k<=j;k++)
		{
			pre[k]=pre[k-1]+1ll*(s[k]=='R')*k;
			prec[k]=prec[k-1]+(s[k]=='R');
		}
		suf[j]=sufc[j]=0;
		for(int k=j-1;k>=i;k--)
		{
			suf[k]=suf[k+1]+1ll*(s[k]=='L')*k;
			sufc[k]=sufc[k+1]+(s[k]=='L');
		}
		for(int k=i+1;k<j;k++)
		{
			int letu=prec[k-1],ritu=sufc[k+1];
			if(s[k]=='L')
			{
				//cout<<k<<" < "<<letu<<" "<<ritu<<"\n";
				if(letu<=ritu)
				{
					int lasre=ritu-letu+1;
					int Lasre=findre(k,j,lasre);
					//cout<<k<<" "<<lasre<<" "<<Lasre<<" "<<letu<<" "<<ritu<<"\n";
					ll as=k+((suf[k+1]-suf[Lasre+1]-pre[k-1])<<1)-i;
					printf("%lld ",as);
				}
				else
				{
					int lasle=letu-ritu;
					int Lasle=findle(i,k,lasle);
					//cout<<"R"<<k<<" "<<letu<<" "<<ritu<<" "<<lasle<<" "<<Lasle<<" "<<pre[k-1]<<" "<<pre[Lasle-1]<<" "<<suf[k+1]<<"\n";
					ll as=k-((pre[k-1]-pre[Lasle-1]-suf[k+1])<<1)+j;
					printf("%lld ",as);
				}
			}
			else if(ritu<=letu)
			{
				int lasle=letu-ritu+1;
				int Lasle=findle(i,k,lasle);
				//cout<<"L"<<k<<" "<<lasle<<" "<<Lasle<<" "<<letu<<" "<<ritu<<" "<<(pre[k-1]-pre[Lasle-1])<<"\n";
				ll as=-((pre[k-1]-pre[Lasle-1]-suf[k+1])<<1)+j-k;
				printf("%lld ",as);
			}
			else
			{
				int lasre=ritu-letu;
				int Lasre=findre(k,j,lasre);
				//cout<<"R"<<k<<" "<<letu<<" "<<ritu<<" "<<lasre<<" "<<Lasre<<"\n";//<<" "<<pre[k-1]<<" "<<pre[Lasle-1]<<" "<<suf[k+1]<<"\n";
				ll as=((suf[k+1]-suf[Lasre+1]-pre[k-1])<<1)-i-k;
				printf("%lld ",as);
			}
		}
		i=j-1;
	}
	return 0;
}
