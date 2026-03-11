#include <bits/stdc++.h>
#define int long long
using namespace std;
inline void solve();
// STRAW BERRY by Tangyixiao qaq
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("berry.in", "r", stdin);
	freopen("berry.out", "w", stdout);

#if __LINE__ != 12
	cout << "I AK IOI";
#endif

	int T = 1;
	cin >> T;
	for (int _ = 1; _ <= T; _++)	{
		solve();
		cout << "\n";
	}
	return 0;
}
inline void solve(){
	int x, y;
	cin >> x >> y;
	/*

	if(x>y){
		swap(x,y);
	}
	if(y<=1ll){
		cout<<"No";
		return;
	}
	if(x==1ll){
		if(y&1ll){
			cout<<"Yes";
		}
		else{
			cout<<"No";
		}
		return;
	}
	if(x==0ll){
		cout<<"Yes";
		return;
	}
	if(x&1ll || y&1ll){
		cout<<"Yes";
		return;
	}
	if(x==2ll){
		cout<<"No";
		return;
	}
	*/

	if (abs(x - y) > 1)	{
		cout << "Yes";
	}
	else	{
		cout << "No";
	}
	return;
}
/*
if a people live a peace life

4 8


3 5
1 6

4 8
2 9

6 1

0 2
1 1

0 4
2 0 is wrong
1 1 is correct


0 3
1 1 is correct

0 5
2 1 is correct

0 6
3 0 is wrong
2 2
3 1 is wrong
1 4 as
2 2 bs
1 3 as


.
.

3 1
1 2

5 1
1.
3 2
1.1.
1 3
1.2.
4 1.

4 1
1.
2 2
1 3
2.



3 1

1 10

1
2 1
bi shu

5 0
3 1
1 2

6 0
0 3
1 2
.



4 8
0 12

*/
