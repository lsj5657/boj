#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double

int n;
int board[1005][1005];
int b[1005][1005], s[1005][1005];
int dx[4]{1,0,-1,0};
int dy[4]{0,1,0,-1};
bool vis[1005][1005];

char r[1005][1005], c[1005][1005];

void func(int x, int y){

	for(int dir = 0; dir < 4; dir++){
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if(nx<1 || nx> n || ny<1 || ny>n) continue;

		if(dir == 0){

			if(c[x][y] == '<'){
				b[nx][ny]--;
			}
			else if(c[x][y] == '>'){
				s[nx][ny]--;
			}
		}
		if(dir == 1){
			if(r[x][y] == '<'){
				b[nx][ny]--;
			}
			else if(r[x][y] == '>'){
				s[nx][ny]--;
			}
		}
		if(dir == 2){
			if(c[nx][ny] == '<'){
				s[nx][ny]--;
			}
			else if(c[nx][ny] == '>'){
				b[nx][ny]--;
			}
		}
		if(dir == 3){
			if(r[nx][ny] == '<'){
				s[nx][ny]--;
			}
			else if(r[nx][ny] == '>'){
				b[nx][ny]--;
			}
		}
	}
}


signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n - 1; j++){
			cin >> r[i][j];
			if(r[i][j] == '<'){
				b[i][j + 1]++;
				s[i][j]++;
			}
			else{
				b[i][j]++;
				s[i][j + 1]++;
			}
		}
	}

	for(int i = 1; i <= n - 1; i++){
		for(int j = 1; j <= n; j++){
			cin >> c[i][j];

			if(c[i][j] == '<'){
				s[i][j]++;
				b[i + 1][j]++;
			}
			else{
				s[i + 1][j]++;
				b[i][j]++;
			}
		}
	}


	int st = 1; int en = n * n;
	queue<tuple<int, int, int>> q;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(b[i][j] && !s[i][j]){
				q.push({1,i,j});
				vis[i][j] = 1;
			}
			else if(s[i][j] && !b[i][j]){
				q.push({0,i,j});
				vis[i][j] = 1;
			}
		}
	}


	while(!q.empty()){
		int state, x, y;
		tie(state, x, y) = q.front(); q.pop();

		//cout << "state x y: " << state << ' ' << x << ' ' << y << '\n';

		if(state == 1){
			board[x][y] = en--;

		}
		else if(state == 0){
			board[x][y] = st++;
		}
		func(x, y);

		for(int dir = 0; dir < 4; dir++){
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if(nx<1 || nx>n || ny<1 || ny>n) continue;
			if(vis[nx][ny]) continue;

			if(b[nx][ny] && !s[nx][ny]){
				vis[nx][ny] = 1;
				q.push({1,nx,ny});
			}
			else if(s[nx][ny] && !b[nx][ny]){
				vis[nx][ny] = 1;
				q.push({0,nx,ny});
			}

		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(!board[i][j]) board[i][j] = st++;
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}


}