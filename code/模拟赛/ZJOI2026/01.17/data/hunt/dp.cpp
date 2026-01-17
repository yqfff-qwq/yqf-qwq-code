#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int main(){
    /*while(1){
        system("dt.exe > a.in");
        system("std.exe < a.in > 1.out");
        system("brute.exe < a.in > 2.out");
        if(system("fc 1.out 2.out /n"))break;
    }*/
   mt19937 mt;
    int x,l,r;
    scanf("%d%d%d",&x,&l,&r);
    for(int i=l;i<=r;i++){
        Sleep(1000);
        string s="dt.exe > ",t=to_string(x)+"_",p=t;
        t=t+to_string(i),t=t+".in";
        p=p+to_string(i),p=p+".out";
        s=s+t;
        cout<<s<<endl;
        system(s.c_str());
        s="hunt.exe < ";s=s+t;s=s+" > ";s=s+p;
        cout<<s<<endl;
        system(s.c_str());
   }
    return 0;
}