#include<bits/stdc++.h>
#define Fe(i,l,r) for(int i=l;i<=r;++i)
#define F(i,l,r) for(int i=l;i<r;++i)
#define pr(...) //fprintf(stderr,__VA_ARGS__)
const int N=1e6+8;
int n,m,pv[N],pos[N],ans[N];
const int BUF_SZ=1e6;

char ib[BUF_SZ+1],*ip=ib+BUF_SZ,ob[1<<24],*op=ob;
int read(int L,int R){
	size_t n=ib+BUF_SZ-ip;
	if(n<100){
		memcpy(ib,ip,n);
		fread(ib+n,1,BUF_SZ-n,stdin)[ib+n]=0;
		ip=ib;
	}
	int x=0;
	while(*ip<48)++ip;
	while(*ip>47)x=x*10+*ip++-48;
	assert(L<=x&&x<=R);
	return x;
}
void print(int x){
	char ss[20];
	int sp=0;
	do ss[sp++]=x%10+48;while(x/=10);
	while(sp)*op++=ss[--sp];
	*op++=10;
}

struct Q{
	int l,r,id;
	bool operator<(const Q &q)const{return l<q.l;}
}qs[N],ps[N*4];
int pp=0;

int bit[N],sl[N],sr[N];
void inc(int x,int a){
	pr("inc %d,%d\n",x,a);
	for(;x;x-=x&-x)bit[x]+=a;
}
int sum(int x){
	int s=0;
	pr("sum %d = ",x);
	for(;x<=n+1;x+=x&-x)s+=bit[x];
	pr("%d\n",s);
	return s;
}

int main(){
	n=read(1,1e6);
	m=read(1,1e6);
	Fe(i,1,n){
		int x=read(1,n);
		pv[i]=pos[x];
		pos[x]=i;
	}
	int res=n+1;
	Fe(i,1,n+1){
		int r=pos[i],l=r;
		while(pv[l])l=pv[l];
		if(r){
			int w=pos[i-1];
			int l2=0,r2=n+1;
			while(w){
				if(w>r)r2=w;
				else if(w<l){
					l2=w;
					break;
				}else{
					goto o;
				}
				w=pv[w];
			}
			
			pr("%d: %d..%d %d..%d\n",i,l2+1,l,r,r2-1);
			ps[pp++]=Q{l2+1,r2-1,1};
			ps[pp++]=Q{l+1,r2-1,-1};
			ps[pp++]=Q{l2+1,r-1,-1};
			ps[pp++]=Q{l+1,r-1,1};
			//rect l2+1..l r..r2-1 ans-=1
		}else{
			int w=pos[i-1];
			if(w){
				//w<l
				++sl[w+1];
				pr("%d: %d.. ..\n",i,w+1);
				while(pv[w]){
					// pv[w]<l r<w ans--
					ps[pp++]=Q{pv[w]+1,w-1,1};
					w=pv[w];
					pr("%d: %d.. ..%d\n",i,pv[w]+1,w-1);
				}
				// r<pv[w]
				++sr[w-1];
				pr("%d: .. ..%d\n",i,w-1);
			}else{
				--res;
			}
		}
		o:;
	}
	Fe(i,1,n+1)sl[i]+=sl[i-1];
	for(int i=n+1;i>=1;--i)sr[i-1]+=sr[i];
	F(i,0,m){
		int l=read(1,n),r=read(l,n);
		qs[i]=Q{l,r,i};
		ans[i]=res-sl[l]-sr[r];
		pr("Q %d,%d: %d - %d - %d + ?\n",l,r,res,sl[l],sr[r]);
	}
	std::sort(ps,ps+pp);
	std::sort(qs,qs+m);
	int p=0;
	F(i,0,m){
		for(;p<pp&&ps[p].l<=qs[i].l;++p)inc(ps[p].r,ps[p].id);
		ans[qs[i].id]-=sum(qs[i].r);
	}
	F(i,0,m)print(ans[i]);
	fwrite(ob,1,op-ob,stdout);
	return 0;
}

