#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &x)
{
	bool f=0;
	x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f^=1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^'0');
		c=getchar();
	}
	if(f)
	{
		x=-x;
	}
}
void write(ll x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>=10)
	{
		write(x/10);
	}
	putchar((x%10)^'0');
}
const int N=510;
const int M=N*N+100;
int n,a[N];
vector<int>b;
bool d[M];
namespace baoli
{
	int posx[N],posy[N],mxax[N],mxay[N];
	void main()
	{
		for(int i=0;i<n;i++)
		{
			read(posx[i]);
			read(posy[i]);
		}
		ll as=0x3f3f3f3f3f3f3f3fll;
		for(int i=0;i<(1<<n);i++)
		{
			int mxx=0,mxy=0,frx=0,fry=0;
			ll sux=0,suy=0;
			memset(mxax,0,sizeof(mxax));
			memset(mxay,0,sizeof(mxay));
			for(int j=0;j<n;j++)
			{
				if((i>>j)&1)
				{
					mxx=max(mxx,posx[j]);
					frx=max(frx,posx[j]+posy[j]);
					if(mxax[posx[j]]<posy[j])
					{
						sux-=mxax[posx[j]];
						sux+=posy[j];
						mxax[posx[j]]=posy[j];
					}
				}
				else
				{
					mxy=max(mxy,posx[j]);
					fry=max(fry,posx[j]+posy[j]);
					if(mxay[posx[j]]<posy[j])
					{
						suy-=mxay[posx[j]];
						suy+=posy[j];
						mxay[posx[j]]=posy[j];
					}
				}
				if(i==425)
				{
					//cerr<<"try "<<j<<" "<<mxx<<" "<<sux<<" "<<frx<<" "<<mxy<<" "<<suy<<" "<<fry<<"\n";
				}
			}
			ll pr=as;
			as=min(as,max(((mxx+sux)<<1)-frx,((mxy+suy)<<1)-fry));
			//if(as<pr||i==425)
			//cerr<<i<<" "<<as<<" "<<mxx<<" "<<sux<<" "<<frx<<" "<<mxy<<" "<<suy<<" "<<fry<<"\n";
		}
		write(as);
		putchar('\n');
	}
}
int main()
{
	freopen("couple.in","r",stdin);
	freopen("couple.out","w",stdout);
	int tt;
	read(tt);
	while(tt--)
	{
		memset(a,0,sizeof(a));
		memset(d,0,sizeof(d));
		read(n);
		if(n<=10)
		{
			baoli::main();
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			int x,y;
			read(x);
			read(y);
			a[x]=max(a[x],y);
		}
		b.clear();
		b.push_back(0);
		for(int i=1;i<N;i++)
		{
			if(a[i])
			{
				b.push_back(i);
			}
		}
		ll as=0x3f3f3f3f3f3f3f3fll;
		d[0]=1;
		vector<ll>su(b.size(),0);
		for(int i=1;i<b.size();i++)
		{
			su[i]=su[i-1]+a[b[i]];
		}
		for(int i=0;i+1<b.size();i++)
		{
			ll x=a[b[i]],y=((su[b.size()-2]-su[i])<<1)+a[b.back()]+b.back()-b[i];
			//cerr<<i<<" "<<x<<" "<<y<<" "<<((su[b.size()-2]-su[i])<<1)<<" "<<a[b.back()]<<" "<<(b.back()-b[i])<<" "<<(i!=0?su[i-1]:0)<<" "<<b[i]<<"\n";
			for(int j=0;j<M;j++)
			{
				if(d[j])
				{
					as=min(as,max(x+(j<<1)+b[i],y+((i!=0?su[i-1]-j:-j)<<1)+b[i]));
					//cerr<<"change "<<as<<" "<<j<<"\n";
				}
			}
			for(int j=M;j>=a[b[i]];j--)
			{
				d[j]|=d[j-a[b[i]]];
			}
		}
		write(as);
		putchar('\n');
	}
	return 0;
}
