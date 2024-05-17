#include<bits/stdc++.h>
using namespace std;
#define int long long
#define X first
#define Y second

int n, m;
int board[15][15];
bool vis[15][15][2][2];
int dx[4]{0,1,0,-1};
int dy[4]{1,0,-1,0};

bool func(int x, int y){
	bool lr = 0, ud = 0;

	for(int dir = 0; dir < 4; dir++){
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if(!board[nx][ny]){
			if(dir == 0 || dir == 2) ud = 1;
			if(dir == 1 || dir == 3) lr = 1;
		}
	}


	if(ud && lr) return 0;
	else return 1;
}

signed main(){
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> board[i][j];
		}
	}

	priority_queue<tuple<int, int, int,int,int>> pq;

	vis[0][0][0][0] = 1;
	pq.push({-0,0,0,0,0});

	while(!pq.empty()){
		int d, x, y, t, c;
		tie(d, x, y, t, c) = pq.top(); pq.pop();
		d = -d;

		//cout << "x y d t: " << x << ' ' << y << ' ' << d << ' ' << t << '\n';

		if(x == n - 1 && y == n - 1){
			cout << d;
			break;
		}

		for(int dir = 0; dir < 4; dir++){
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if(nx < 0 || nx >= n || ny < 0 || ny >= n)continue;


			if(!board[nx][ny]){
				if(!func(nx, ny)) continue;
				if(c == 1 || t==1) continue;
				if(vis[nx][ny][t + 1][c]) continue;
				int rem = m - d % m;
				vis[nx][ny][t + 1][c] = 1;
				pq.push({-(d+rem),nx,ny,1,1});
			}
			else if(board[nx][ny] == 1){
				if(vis[nx][ny][t][c])continue;
				vis[nx][ny][t][c] = 1;
				pq.push({-(d+1),nx,ny,0,c});
			}
			else{
				if(vis[nx][ny][t][c]) continue;
				if(t == 1) continue;
				int rem = board[nx][ny] -d % board[nx][ny];
				vis[nx][ny][t+1][c] = 1;
				
				pq.push({-(d+rem), nx,ny,1,c});
			}
		}
	}

}
