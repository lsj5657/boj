#include<bits/stdc++.h>
using namespace std;
#define int long long

int n = 19;
int board[22][22];

bool func(int x, int y){

	
	int ux = x;
	while(ux - 1 >= 1 && board[ux-1][y] == board[x][y]) ux--;
	int dx = x;
	while(dx + 1 <= n && board[dx+1][y] == board[x][y]) dx++;
	int c1 = (dx - ux + 1);
	//cout << "dx ux: " << dx << ' ' << ux << '\n';
	if(c1 == 5) return 1;

	int ly = y;
	int ry = y;
	while(ly - 1 >= 1 && board[x][ly-1] == board[x][y]) ly--;
	while(ry + 1 <= n && board[x][ry+1] == board[x][y]) ry++;
	//cout << "ly ry: " << ly << ' ' << ry << '\n';
	if(ry - ly + 1 == 5) return 1;


	int sx = x; int sy = y;
	while(sx - 1 >= 1 && sy - 1 >= 1 && board[sx - 1][sy - 1] == board[x][y]){
		sx--;
		sy--;
	}
	int ex = x; int ey = y;
	while(ex + 1 <= n && ey + 1 <= n && board[ex + 1][ey + 1] == board[x][y]){
		ex++; ey++;
	}
	//cout << "sx ex: " << sx << ' ' << ex << '\n';

	if(ex - sx + 1 == 5) return 1;

	sx = x; sy = y; ex = x; ey = y;

	while(sx - 1 >= 1 && sy + 1 <= n && board[sx - 1][sy + 1] == board[x][y]){
		sx--; sy++;
	}
	while(ex + 1 <= n && ey - 1 >= 1 && board[ex + 1][ey - 1] == board[x][y]){
		ex++;
		ey--;
	}


	//cout << "sx ex: " << sx << ' ' << ex << '\n';
	//cout << "ex-sx+1: " << ex - sx + 1 << '\n';
	if(ex - sx + 1 == 5) return 1;

	return 0;
}

signed main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int m;
	cin >> m;
	memset(board, -1, sizeof(board));

	int ans = -1;
	for(int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		board[x][y] = i % 2;

		
		
		if(func(x, y) && ans==-1) {
			ans = i;
		}
	}

	cout << ans;
}