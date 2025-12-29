#include<bits/stdc++.h>
#define ll long long
#define lll unsigned long long
#define mkp make_pair
#define pi pair<int, int>
#define vc vector
#define INF 2147483647
#define endl "\n"
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

constexpr int N = 4011;

int n, m, Q, fx, fy, sx, sy;
int a[N][N];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
bitset<N> vis[N];
queue<pi> q;


void bfs(int X, int Y, int col)
{
	q.push(mkp(X, Y));
	vis[X][Y] = 1;
	while (!q.empty())
	{
		int x, y, nx, ny;
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if(vis[nx][ny] || a[nx][ny] != col || nx < fx || nx > sx || ny < fy || ny > sy) continue;
			q.push(mkp(nx, ny));
			vis[nx][ny] = 1;
		}
	}
}

signed main()
{
	IOS;
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);
	cin >> n >> m >> Q;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char ch;
			cin >> ch;
			a[i][j] = ch - 'A' + 1;
		}
	}
	while (Q--)
	{
		int ans = 0;
		cin >> fx >> fy >> sx >> sy;
		for (int i = fx; i <= sx; i++)
		{
			for (int j = fy; j <= sy; j++)
			{
				if(!vis[i][j])
				{
					ans++;
					bfs(i, j, a[i][j]);
				}
			}
		}
		for (int i = fx; i <= sx; i++)
		{
			vis[i].reset();
		}
		cout << ans << endl;
	}
	return 0;
}
/*
7
4
2
1
4
1
3
3
3
*/