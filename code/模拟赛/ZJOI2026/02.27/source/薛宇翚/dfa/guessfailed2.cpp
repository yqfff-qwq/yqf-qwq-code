#include <bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int n,m;
string s[N];
long long as;
int main()
{
  freopen("dfa.in","r",stdin);
  freopen("dfa.out","w",stdout);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    cin>>s[i];
    for(int j=1;j<i;j++)
    {
      if(s[i].find(s[j])!=-1||s[j].find(s[i])!=-1)
      {
        as++;
      }
    }
  }
  cout<<as<<"\n";
  return 0;
}
