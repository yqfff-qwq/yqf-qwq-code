#include<bits/stdc++.h>
using namespace std;
int n,m;
int st[22][3][3],oz[1<<22],lg[1<<22];
int co[22],dp[1<<22];
int main(){
    //freopen("paint.in","r",stdin);
    //freopen("paint.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0,u,v,x,y;i<m;i++){
        scanf("%d%d%d%d",&u,&x,&v,&y);
        u--,v--;
        st[u][x][y]|=(1<<v);
        st[v][y][x]|=(1<<u);
    }
    lg[0]=-1;
    for(int s=1;s<(1<<n);s++)lg[s]=lg[s>>1]+1,oz[s]=lg[s&-s];
    dp[0]=1;
    for(int s=1;s<(1<<n);s++){
        int x=oz[s];
        for(int t=0;t<2;t++){
            int vis=(1<<x);bool fl=0;
            co[x]=t;queue<int>q;q.push(x);
            while(!q.empty()){
                int u=q.front();q.pop();
                for(int o=0;o<2;o++){
                    for(int j=s&st[u][co[u]][o^1];j;j-=(j&-j)){
                        int v=oz[j];
                        if(!((vis>>v)&1))co[v]=o,q.push(v),vis|=(1<<v);
                        else if(co[v]!=o){fl=1;break;}
                    }
                }
                if(fl)break;
            }
            if(!fl)dp[s]+=dp[s^vis];
        }
    }
    long long ans=0;
    for(int s=0;s<(1<<n);s++){
        bool fl=0;
        int s_=((1<<n)-1)^s,vis=0;
        queue<int>q;
        for(int i=0;i<n;i++)if((s>>i)&1){
            if(st[i][2][2]&s){fl=1;break;}
            for(int o=0;o<2;o++){
                for(int j=s_&st[i][2][o^1];j;j-=(j&-j)){
                    int v=oz[j];
                    if(!((vis>>v)&1))co[v]=o,q.push(v),vis|=(1<<v);
                    else if(co[v]!=o){fl=1;break;}
                }
            }
        }
        if(fl)continue;
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int o=0;o<2;o++){
                for(int j=s_&st[u][co[u]][o^1];j;j-=(j&-j)){
                    int v=oz[j];
                    if(!((vis>>v)&1))co[v]=o,q.push(v),vis|=(1<<v);
                    else if(co[v]!=o){fl=1;break;}
                }
            }
            if(fl)break;
        }
        if(!fl)ans+=dp[s_^vis];
    }
    return printf("%lld",ans),0;
}