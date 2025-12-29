#include<bits/stdc++.h>
using namespace std;
signed main(){
    int ct=0;
    while (1){
        system("./mkdata");
        system("./perimeter");
        system("./bf");
        if (system("diff perimeter.out perimeter_.out")){
            cout<<"WA\n";
            break;
        }
        ++ct;
        cout<<"Test Case "<<ct<<" : Accepted\n";
    }
}