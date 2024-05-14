#include <bits/stdc++.h>
using namespace std;

int board[10][10];
int n, m;
int dir[65];
vector<tuple<int, int, int>> v;
int mn = 100;


//각 방향마다 감시 가능한 구역을 설정하는 함수들
void lc(int x, int y) {
	for (int i = y - 1; i >= 0; i--) {
		if (board[x][i] == 6)break;
		if (board[x][i] >= 1 && board[x][i] <= 5) continue;
		board[x][i] = 7;
	}
}

void rc(int x, int y) {
	for (int i = y + 1; i < m; i++) {
		if (board[x][i] == 6)break;
		if (board[x][i] >= 1 && board[x][i] <= 5) continue;
		board[x][i] = 7;
	}
	
}

void uc(int x, int y) {
	for (int i = x - 1; i >= 0; i--) {
		if (board[i][y] == 6)break;
		if (board[i][y] >= 1 && board[i][y] <= 5)continue;
		board[i][y] = 7;
	}
}
void dc(int x, int y) {
	for (int i = x + 1; i < n; i++) {
		if (board[i][y] == 6)break;
		if (board[i][y] >= 1 && board[i][y] <= 5)continue;
		board[i][y] = 7;
	}
}

void cctv1(int x, int y, int dir) {
	if (dir == 0) uc(x, y);
	else if (dir == 1) rc(x, y);
	else if (dir == 2) dc(x, y);
	else  lc(x, y);
}

void cctv2(int x, int y, int dir) {
	if (dir == 0) {
		uc(x, y); dc(x, y);
	}
	else {
		rc(x, y); lc(x, y);
	}
}

void cctv3(int x, int y, int dir) {
	if (dir == 0) {
		uc(x, y); rc(x, y);
	}
	else if (dir == 1) {
		rc(x, y);
		dc(x, y);
	}
	else if (dir == 2) {
		dc(x, y);
		lc(x, y);
	}
	else {
		lc(x, y);
		uc(x, y);
	}
}

void cctv4(int x, int y, int dir) {
	if (dir == 0) {
		uc(x, y);
		lc(x, y);
		rc(x, y);
	}
	else if (dir == 1) {
		rc(x, y);
		uc(x, y);
		dc(x, y);
	}
	else if (dir == 2) {
		dc(x, y);
		rc(x, y);
		lc(x, y);
	}
	else {
		lc(x, y);
		uc(x, y);
		dc(x, y);
	}
}



void cctv5(int x,int y) {
	uc(x, y); dc(x, y); lc(x, y); rc(x, y);
}

//각 cctv의 방향을 정해주는 백트래킹 함수
void direction(int k, int vsz) {
	if (k == vsz) {
		//원본 초기화 
	
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 7)board[i][j] = 0;
			}
		}
		for (int i = 0; i < k; i++) {
			int type = get<0>(v[i]);
			if (type == 1) {
				cctv1(get<1>(v[i]), get<2>(v[i]), dir[i]);
			}
			else if (type == 2) {
				cctv2(get<1>(v[i]), get<2>(v[i]), dir[i]);
			}
			else if (type == 3) {
				cctv3(get<1>(v[i]), get<2>(v[i]), dir[i]);
			}
			else if (type == 4) {
				cctv4(get<1>(v[i]), get<2>(v[i]), dir[i]);
			}
			else {
				cctv5(get<1>(v[i]), get<2>(v[i]));
			}
		}

		int cnt = 0;
	
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 0) cnt++;
			}
		}
		
		if (cnt < mn) mn = cnt;
		return;
		
	}
	if (get<0>(v[k]) == 2) {
		for (int i = 0; i < 2; i++) {
			dir[k] = i;
			direction(k + 1, vsz);
		}
	}
	else if (get<0>(v[k]) == 5) {
			dir[k] = 0;
			direction(k + 1, vsz);
	}
	else {
		for (int i = 0; i < 4; i++) {
			dir[k] = i;
			direction(k + 1, vsz);
		}
	}

}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] >= 1 && board[i][j] <= 5) {
				v.push_back({ board[i][j],i,j });
			}
		}
	}

	int vsz = v.size();
	direction(0, vsz);

	cout << mn;
}