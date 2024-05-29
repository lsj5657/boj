#include <bits/stdc++.h>
using namespace std;

int d[1001][1001];
int a[1001][1001];
int n, m;
int dx[3]{ 0,-1,-1 };
int dy[3]{ -1,-1,0 };

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			d[i][j] = a[i][j];
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int dir = 0; dir < 3; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				d[i][j] = max(d[i][j], d[nx][ny] + a[i][j]);
			}
		}
	}



	cout << d[n][m];
}