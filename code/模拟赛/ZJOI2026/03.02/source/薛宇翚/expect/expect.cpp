#include <bits/stdc++.h>
using namespace std;
int main()
{
  freopen("expect.in","r",stdin);
  freopen("expect.out","w",stdout);
  int n;
  cin>>n;
  for(int i=0;i<(1<<n);i++)
  {
    int x;
    cin>>x;
  }
  cout<<"0\n";
  int b=(1<<n);
  for(int i=1;i<(1<<n);i++)
  {
    cout<<b<<"\n";
  }
  return 0;
}
