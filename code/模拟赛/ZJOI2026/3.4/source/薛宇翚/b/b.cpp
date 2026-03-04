//你希望确保你的朋友获得最大的快乐，那显然意味着让你的朋友永远被困在这个快乐宫殿里。
//上述材料给你带来了怎样的思考？请写一篇文章，不少于 800 字。
#include <bits/stdc++.h>
using namespace std;
int main()
{
  freopen("b.in","r",stdin);
  freopen("b.out","w",stdout);
  int n,e;
  scanf("%d%d",&n,&e);
  if(e==1)
  {
    int as=n/2;
    printf("%d\n",as);
  }
  else
  {
    int as=max(e-1,(n+1)/2);
    printf("%d\n",as);
  }
  return 0;
}
