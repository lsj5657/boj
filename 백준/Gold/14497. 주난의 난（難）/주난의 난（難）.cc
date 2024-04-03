#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
char board[305][305];
bool vis[305][305];

int dx[4]{1,0,-1,0};
int dy[4]{0,1,0,-1};



signed main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> board[i][j];
		}
	}
	

	

	queue<pair<int, int>> q;
	q.push({x1,y1});
	vis[x1][y1] = 1;
	int jump = 0;
	while(true){
		jump++;
		bool ok = 0;
		vector<pair<int, int>> v;
		while(!q.empty()){
			int x, y;
			tie(x, y) = q.front(); q.pop();
			for(int dir = 0; dir < 4; dir++){
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if(nx<1 || nx>n || ny<1 || ny>m) continue;
				if(vis[nx][ny]) continue;
				if(nx == x2 && ny == y2) ok = 1;
				vis[nx][ny] = 1;
				if(board[nx][ny]=='1'){
					v.push_back({nx,ny});
				}
				else {
					q.push({nx,ny});
				}
			}
		}

		for(auto w : v){
			q.push({w.first,w.second});
		}

		if(ok)break;

	}


	cout << jump;
}
