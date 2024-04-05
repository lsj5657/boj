#include <bits/stdc++.h>
using namespace std;
#define int long long


int n, m;
int board[22][22];
bool vis[22][22];

int dx[4]{1,0,-1,0};
int dy[4]{0,1,0,-1};

int func(){
	int ret = 0;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			vis[i][j] = 0;
		}
	}

	queue<pair<int, int>> q;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(board[i][j] != 2) continue;
			if(vis[i][j]) continue;
			//cout << "i j: " << i << ' ' << j << '\n';
			vis[i][j] = 1;
			q.push({i,j});
			set<pair<int, int>> st;
			int cnt = 0;
			while(!q.empty()){
				int x, y;
				tie(x, y) = q.front(); q.pop();
				cnt++;
				for(int dir = 0; dir < 4; dir++){
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if(nx<1 || nx>n || ny<1 || ny>m) continue;
					if(!board[nx][ny]) st.insert({nx,ny});
					if(vis[nx][ny] || board[nx][ny] != 2) continue;
					vis[nx][ny] = 1;
					q.push({nx,ny});
					
				}
			}

			/*cout << "cnt: " << cnt << '\n';
			cout << "st: ";
			for(auto w : st) cout << w.first << ' ' << w.second << '\n';
			cout << '\n';*/

			if(st.empty()) ret += cnt;
			//cout << "ret: " << ret << '\n';
		}
	}

	return ret;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	vector<pair<int, int>> v;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> board[i][j];
			if(!board[i][j]) v.push_back({i,j});
		}
	}

	int ans = 0;
	for(int i = 0; i < v.size(); i++){
		for(int j = i + 1; j < v.size(); j++){
			int x1, y1, x2, y2;
			tie(x1, y1) = v[i]; tie(x2, y2) = v[j];
			board[x1][y1] = 1; board[x2][y2] = 1;
			int f = func();
			/*cout << "x1 y1 x2 y2: " << x1 << ' ' << x2 << ' ' << y1 << ' ' << y2 << '\n';
			cout << "f: " << f << '\n';*/
			ans = max(ans, f);
			board[x1][y1] = 0; board[x2][y2] = 0;
		}
	}

	cout << ans;
	

}



