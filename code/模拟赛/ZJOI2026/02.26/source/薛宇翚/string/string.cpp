#include <bits/stdc++.h>
using namespace std;
const int M=1e9+7;
string s,t;
int n;
vector<string>S,T;
vector<int>acts,actt,bcts,bctt;
void dfs(int x,int y,string z)
{
  int le=(x?t.size():s.size());
  if(y>=le)
  {
    if(x)
    {
      T.push_back(z);
    }
    else
    {
      S.push_back(z);
    }
    return;
  }
  char w=(x?t[y]:s[y]);
  if(w!='B')
  {
    dfs(x,y+1,z+"A");
  }
  if(w!='A')
  {
    dfs(x,y+1,z+"B");
  }
}
int main()
{
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
  cin>>s>>t>>n;
  dfs(0,0,"");
  dfs(1,0,"");
  for(int i=0;i<S.size();i++)
  {
    int ct=0;
    for(int j=0;j<S[i].size();j++)
    {
      ct+=(S[i][j]=='A');
    }
    acts.push_back(ct);
    bcts.push_back(S[i].size()-ct);
  }
  for(int i=0;i<T.size();i++)
  {
    int ct=0;
    for(int j=0;j<T[i].size();j++)
    {
      ct+=(T[i][j]=='A');
    }
    actt.push_back(ct);
    bctt.push_back(T[i].size()-ct);
  }
  int as=0;
  for(int i=0;i<S.size();i++)
  {
    for(int j=0;j<T.size();j++)
    {
      for(int la=1;la<=n;la++)
      {
        for(int lb=1;lb<=n;lb++)
        {
          //cout<<i<<" "<<j<<" "<<S[i]<<" "<<T[j]<<" "<<la<<" "<<lb<<" "<<acts[i]<<" "<<bcts[i]<<" "<<actt[j]<<" "<<bctt[j]<<"\n";
          if(acts[i]*la+bcts[i]*lb!=actt[j]*la+bctt[j]*lb)
          {
            continue;
          }
          //cout<<"check passed\n";
          for(int sa=0;sa<(1<<la);sa++)
          {
            string ss="";
            for(int k=0;k<la;k++)
            {
              if((sa>>k)&1)
              {
                ss+="1";
              }
              else
              {
                ss+="0";
              }
            }
            for(int ta=0;ta<(1<<lb);ta++)
            {
              string tt="";
              for(int k=0;k<lb;k++)
              {
                if((ta>>k)&1)
                {
                  tt+="1";
                }
                else
                {
                  tt+="0";
                }
              }
              string uu="",vv="";
              for(int k=0;k<S[i].size();k++)
              {
                if(S[i][k]=='A')
                {
                  uu+=ss;
                }
                else
                {
                  uu+=tt;
                }
              }
              for(int k=0;k<T[j].size();k++)
              {
                if(T[j][k]=='A')
                {
                  vv+=ss;
                }
                else
                {
                  vv+=tt;
                }
              }
              //cout<<i<<" "<<j<<" "<<S[i]<<" "<<T[j]<<" "<<sa<<" "<<ta<<" "<<ss<<" "<<tt<<" "<<uu<<" "<<vv<<"\n";
              if(uu==vv)
              {
                as=(as+1)%M;
              }
            }
          }
        }
      }
    }
  }
  cout<<as<<"\n";
  return 0;
}
