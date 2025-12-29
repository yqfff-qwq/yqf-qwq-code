#include <bits/stdc++.h>
using namespace std;
#define int long long
void read(int &x)
{
	x=0;
	bool f=0;
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
struct mvmt
{
	int dir,ti;
	mvmt(int x=0,int y=0):dir(x),ti(y){}
};
signed main()
{
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	int t;
	read(t);
	while(t--)
	{
		deque<mvmt>aq,bq;
		int n,m;
		read(n);
		for(int i=1;i<=n;i++)
		{
			int x,y;
			read(x);
			read(y);
			aq.push_back(mvmt(x,y));
		}
		read(m);
		for(int i=1;i<=m;i++)
		{
			int x,y;
			read(x);
			read(y);
			bq.push_back(mvmt(x,y));
		}
		map<int,int>d;
		int s=0;
		d[0]++;
		d[2]--;
		while(!aq.empty()&&!bq.empty())
		{
			mvmt cura=aq.front(),curb=bq.front();
			mvmt cur=mvmt(curb.dir-cura.dir,min(cura.ti,curb.ti));
			cura.ti-=cur.ti;
			curb.ti-=cur.ti;
			aq.pop_front();
			bq.pop_front();
			if(cura.ti)
			{
				aq.push_front(cura);
			}
			if(curb.ti)
			{
				bq.push_front(curb);
			}
			if(!cur.dir)
			{
				d[s]+=cur.ti;
				d[s+2]-=cur.ti;
			}
			else if(cur.dir==1)
			{
				int ne=s+1,nf=s+cur.ti;
				d[ne]++;
				d[ne+1]++;
				d[nf+1]--;
				d[nf+2]--;
				s=nf;
			}
			else if(cur.dir==-1)
			{
				int ne=s-cur.ti,nf=s-1;
				d[ne]++;
				d[ne+1]++;
				d[nf+1]--;
				d[nf+2]--;
				s=ne;
			}
			else if(cur.dir==2)
			{
				int ne=s+2,nf=s+(cur.ti<<1);
				d[ne]++;
				d[nf+2]--;
				s=nf;
			}
			else if(cur.dir==-2)
			{
				int ne=s-(cur.ti<<1),nf=s-2;
				d[ne]++;
				d[nf+2]--;
				s=ne;
			}
		}
		int ji=0,ou=0,as=0;
		for(map<int,int>::iterator it=d.begin();it!=d.end();it++)
		{
			int x=(it->first),y=(it->second);
			if(x&1)
			{
				ji+=y;
				as=max(as,ji);
			}
			else
			{
				ou+=y;
				as=max(as,ou);
			}
		}
		printf("%lld\n",as);
	}
	return 0;
}
