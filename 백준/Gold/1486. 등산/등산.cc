#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;


int dx[4]{1,0,-1,0};
int dy[4]{0,1,0,-1};
int board[26][26];
int dist[626][626];
int n, m, t, d;






signed main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m >> t >> d;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			char c; cin >> c;
			if('A' <= c && c <= 'Z'){
				board[i][j] = c - 'A';
			}
			else if('a' <= c && c <= 'z'){
				board[i][j] = (c - 'a') + 26;
			}
		}
	}


	int N = n * m;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			dist[i][j] = 1e9;
		}
	}
	for(int i = 1; i <= N; i++){
		dist[i][i] = 0;
	}



	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			for(int dir = 0; dir < 4; dir++){
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if(nx<1 || nx>n || ny<1 || ny>m) continue;
				if(abs(board[i][j] - board[nx][ny]) > t) continue;
				if(board[i][j] >= board[nx][ny]){
					dist[(i-1)*m+j][(nx-1)*m+ny] = 1;
				}
				else{
					int diff = board[nx][ny] - board[i][j];
					if(diff <= d){
						dist[(i-1)*m+j][(nx-1)*m+ny] = diff * diff;
					}
				}
			}
		}
	}



	for(int k = 1; k <= N; k++){
		for(int i = 1; i <=N; i++){
			for(int j = 1; j <= N; j++){
				dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
			}
		}
	}


	int ans = 0;
	for(int i = 1; i <= N; i++){
		int tot = dist[1][i] + dist[i][1];
		if(tot <= d){
			int x = (i - 1) / m + 1; int y = (i - 1) % m + 1;
			//cout << "i x y: " << i << ' ' << x << ' ' << y << '\n';
			ans = max(ans, board[x][y]);
		}
		//cout << "tot:" << tot << '\n';
	}

	cout << ans;
	



}





