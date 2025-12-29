#include<bits/stdc++.h>
using namespace std;
int N,A[300001],B[300001],b[300001],c[300001];
long long maxn,sum;
#define _wa "WA"
#define _ok "AC"
void quitf(string x,string y)
{
	cout<<x<<" "<<y<<"\n";
	exit(0);
}
void quitp(double x,string y)
{
	cout<<x<<" "<<y<<"\n";
	exit(0);
}
int main(){
	ifstream inf("b.in"),ouf("b.out"),ans("b.ans");
    inf>>N;
    for(int i=1;i<=N;++i)inf>>A[i];
    for(int i=1;i<=N;++i)inf>>B[i];
    ouf>>maxn;
    long long orz;
    ans>>orz;
    if(maxn!=orz)quitf(_wa,"Wrong maximum value");
    for(int i=1;i<=N;++i){
        ouf>>b[i];
    }
    sort(B+1,B+N+1);
    memcpy(c,b,sizeof(b));
    sort(c+1,c+N+1);
    if(memcmp(B,c,sizeof(B)))quitp(0.6,"Array invalid");
    for(int i=1;i<N;++i){
        if(A[i]<A[i+1]&&b[i]>=b[i+1])quitp(0.6,"Array invalid");
        if(A[i]>A[i+1]&&b[i]<=b[i+1])quitp(0.6,"Array invalid");
    }
    for(int i=1;i<N;++i)sum+=abs(b[i]-b[i+1]);
    if(maxn!=sum)quitp(0.6,"Actual value violates answer");
    quitf(_ok,"The answer is correct");
    return 0;
}
