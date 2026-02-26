#include <bits/stdc++.h>
using namespace std;
int main()
{
  freopen("interval.in","r",stdin);
  freopen("interval.output","w",stdout);
  int n,s=0,t=0;
  cin>>n;
  cout<<n<<"\n";
  for(int tt=1;tt<=n;tt++)
  {
    int op,x,y;
    cin>>op>>x>>y;
    if(op==1)
    {
      s++;
      cout<<"Seg="<<s<<": "<<op<<" "<<x<<" "<<y<<"\n";
    }
    else
    {
      t++;
      cout<<"Qry="<<t<<": "<<op<<" "<<x<<" "<<y<<"\n";
    }
  }
  return 0;
}
