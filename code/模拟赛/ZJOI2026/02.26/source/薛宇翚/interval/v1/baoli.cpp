#include <bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int f[N];
int F(int x)
{
  return x==f[x]?x:f[x]=F(f[x]);
}
int main()
{
  freopen("interval.in","r",stdin);
  freopen("interval.ans","w",stdout);
  int n;
  cin>>n;
  for(int i=0;i<N;i++)
  {
    f[i]=i;
  }
  vector<pair<int,int> >seg;
  seg.push_back(make_pair(0,0));
  for(int tt=1;tt<=n;tt++)
  {
    int op,x,y;
    cin>>op>>x>>y;
    if(op==1)
    {
      for(int i=1;i<seg.size();i++)
      {
        if((x<seg[i].first&&seg[i].first<y)||(x<seg[i].second&&seg[i].second<y)||(seg[i].first<x&&x<seg[i].second)||(seg[i].first<y&&y<seg[i].second))
        {
          f[F(i)]=F(seg.size());
          cout<<"Add edge "<<i<<" "<<seg.size()<<"\n";
        }
      }
      if(seg.size()!=1&&seg.back().second-seg.back().first>=y-x)
      {
        cerr<<"Where should I stop? I ask myself.\n";
        cerr<<"Test tt="<<tt<<" Seg.back()="<<seg.back().first<<","<<seg.back().second<<" while input="<<x<<","<<y<<"\n";
      }
      seg.push_back(make_pair(x,y));
    }
    else
    {
      cout<<(F(x)==F(y)?"YES\n":"NO\n");
    }
  }
  return 0;
}
