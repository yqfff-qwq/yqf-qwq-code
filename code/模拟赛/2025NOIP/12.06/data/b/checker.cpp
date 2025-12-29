#include<bits/stdc++.h>
#include"sptestlib.h"
using namespace std;
int N,A[300001],B[300001],b[300001],c[300001];
long long maxn,sum;
int main(int argc,char *argv[]){
    registerLemonChecker(argc,argv);
    int fullscore=perfectScore;
    N=inf.readInt();
    for(int i=1;i<=N;++i)A[i]=inf.readInt();
    for(int i=1;i<=N;++i)B[i]=inf.readInt();
    maxn=ouf.readLong();
    if(maxn!=ans.readLong())quitf(_wa,"Wrong maximum value");
    if(ouf.seekEof())quitp(0.6*fullscore,"Array left blank");
    for(int i=1;i<=N;++i){
        if(ouf.seekEof())quitp(0.6*fullscore,"Array format invalid");
        b[i]=ouf.readInt();
        if(i!=N&&ouf.seekEof())quitp(0.6*fullscore,"Array format invalid");
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
    quitf(_ok,"N = %d",N);
    return 0;
}
