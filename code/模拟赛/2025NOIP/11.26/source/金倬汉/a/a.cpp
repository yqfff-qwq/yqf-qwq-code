#include<bits/stdc++.h>
#define cint const int
#define uint unsigned int
#define cuint const unsigned int
#define ll long long
#define cll const long long
#define ull unsigned long long
#define cull const unsigned long long
using namespace std;
inline int read()
{
	int x=0,zf=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')zf=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch-'0');
		ch=getchar();
	}
	return x*zf;
}
void print(cint x)
{
	if(x<0)
	{
		putchar('-');
		print(-x);
		return;
	}
	if(x<10)
	{
		putchar(x+'0');
		return;
	}
	print(x/10);
	putchar(x%10+'0');
}
void princh(cint x,const char ch)
{
	print(x);
	putchar(ch);
}
char x;
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	char ch=getchar();
	while(ch!='0'&&ch!='1')ch=getchar();
	x=ch;
	int ans=0;
	while(ch==x)
	{
		++ans;
		ch=getchar();
	}
	princh(ans,'\n');
	return 0;
}