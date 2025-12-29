#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define MP make_pair
using namespace std;

namespace annika{
    const int N=4003;
    int n,m,q;
    char s[N][N];
    int f[N][N],cnt;
    int xl,xr,yl,yr;

    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    queue <pii> Q;
    void bfs(int sx,int sy){
        f[sx][sy]=1;
        Q.push(MP(sx,sy));
        while (Q.size()){
            int nx=Q.front().fi,ny=Q.front().se;
            Q.pop();
            for (int i=0;i<4;i++){
                int tx=nx+dx[i],ty=ny+dy[i];
                if (tx<xl || tx>xr || ty<yl || ty>yr || f[tx][ty] || s[tx][ty]!=s[nx][ny]) continue;
                f[tx][ty]=1;
                Q.push(MP(tx,ty));
            }
        }
    }

    void main(){
        cin>>n>>m>>q;
        for (int i=1;i<=n;i++){
            cin>>(s[i]+1);
        }
        while (q--){
            cin>>xl>>yl>>xr>>yr;
            cnt=0;
            for (int i=xl;i<=xr;i++){
                for (int j=yl;j<=yr;j++){
                    f[i][j]=0;
                }
            }
            for (int i=xl;i<=xr;i++){
                for (int j=yl;j<=yr;j++){
                    if (!f[i][j]){
                        cnt++;
                        bfs(i,j);
                    }
                }
            }
            cout<<cnt<<"\n";
        }
    }
}

signed main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    annika::main();

    return 0;
}