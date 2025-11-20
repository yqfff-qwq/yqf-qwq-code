#include<bits/stdc++.h>
using namespace std;
bool check(const string& s){
	int l=0;
	for(char c:s){
		if(c=='(')l+=1;
		else l-=1;
		if(l<0)return false;
	}
	return l==0;
}
int main(){
	freopen("core.in","r",stdin);
	freopen("core.out","w",stdout);
	int id,n,m,k;
	cin>>id>>n>>m>>k;
	vector<string>s(n),t(n);
	for(int i=0;i<n;i++)
	cin>>s[i];
	for(int i=0;i<n;i++)
	cin>>t[i];
	long long ans=0;
} 
