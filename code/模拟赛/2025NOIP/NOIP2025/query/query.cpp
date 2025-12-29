#include<bits/stdc++.h>
// #include <iostream>
using namespace std;

#define int long long
#define REP(i,l,r) for(int i=l;i<=r;i++)
#define DEP(i,r,l) for(int i=r;i>=l;i--)
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back

void read(){}
template<typename T1,typename ...T2>inline void read(T1 &x,T2 &...oth)
{
  x=0;
  int f=0,ch=getchar();
  while(ch<'0'||ch>'9')
  {
      if(ch=='-')
      {
          f=1;
      }
      ch=getchar();
  }
  while('0'<=ch&&ch<='9')
  {
      x=(x<<3)+(x<<1)+(ch^48);
      ch=getchar();
  }
  if(f)
  {
      x=-x;
  }
  read(oth...);
}
namespace YZLK{
    
  void main() {
    
    return;
  }
}

signed main()
{
  // freopen("query.in","r",stdin);
  // freopen("query.out","w",stdout);
  int T=1;
//   read(T);
  while(T--) {
    YZLK::main();
  }

//    fclose(stdin);
//    fclose(stdout);
    return 0;
}