#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define uint unsigned int
#define pii pair<int,int>
#define pb push_back
#define vi vector<int>
const int inf=0x3f3f3f3f;
inline int rd(){
    int x=0,y=1;char c=getchar();
    for(;c<'0'||c>'9';c=getchar())if(c=='-')y=-1;
    for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
    return x*y;
}
int n=2e5;
mt19937_64 gen(time(0));
signed main(){
    freopen("a4_2.in","w",stdout);
    for(int i=1;i<=114;i++)cout<<0;
    for(int i=1;i<=n-114;i++)cout<<gen()%2;
    return 0;
}