#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<iostream>
using namespace std;

 class bigint
 {
 	public:
  		std::vector<int> num;
 };

 bigint operator*(const bigint &A, const int &B)
 // B should not greater than 214748364.
 {
     bigint res;
     res.num = A.num;
     res.num.resize(A.num.size() + 10);
     for (unsigned i = 0; i != A.num.size(); ++i)
         res.num[i] *= B;
     for (unsigned i = 0; i != A.num.size(); ++i)
         if (res.num[i] >= 10)
         {
             res.num[i + 1] += res.num[i] / 10;
             res.num[i] %= 10;
         }
     while (!(res.num.empty() || res.num.back()))
         res.num.pop_back();
     return res;
 }


int main(){
	freopen("mu.in","r",stdin);
	freopen("mu.out","w",stdout);
	return 0;
}
