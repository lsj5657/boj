#include <bits/stdc++.h>
using namespace std;
#define ll long long
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

int n, m;
int board[1005][1005];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}

	string ans = "";
	if (n % 2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m-1; j++) {
				if (i % 2) ans += 'L';
				else ans += 'R';
			}
			if (i < n - 1) ans += 'D';
		}

		cout << ans;
	}
	else if (m % 2) {
		for (int j = 0; j < m; j++) {
			for (int i = 0; i < n-1; i++) {
				if (j % 2) ans += 'U';
				else ans += 'D';
			}
			if (j < m - 1) ans += 'R';
		}

		cout << ans;
	}
	else {
		int mn = 1e9;
		int x, y;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if ((i + j) % 2 == 0) continue;
				if (board[i][j] < mn) {
					mn = board[i][j];
					x = i, y = j;
				}
			}
		}


		if (x % 2) {
			for (int i = 1; i < x; i++) {
				for (int j = 1; j < m; j++) {
					if (i % 2) ans += 'R';
					else ans += 'L';
				}
				ans += 'D';
			}

			if (y == m) {
				int a = x; int b = 1;
				while (b < m) {
					ans += 'D';
					a++;
					ans += 'R';
					b++;
					if (a - 1 == x && b == y) {
						break;
						ans += 'R';
						b++;
					}
					ans += 'U';
					a--;
					ans += 'R';
					b++;
				}

				if (a != n) {
					ans += 'D';
					for (int i = x + 2; i <= n; i++) {
						for (int j = 1; j < m; j++) {
							if (i % 2) ans += 'L';
							else ans += 'R';
						}
						if (i < n) ans += 'D';
					}
				}
			}
			else {
				int a = x; int b = 1;
				while (b < m) {
					ans += 'D';
					a++;
					ans += 'R';
					b++;
					if (a - 1 == x && b == y) {
						ans += 'R';
						b++;
					}
					ans += 'U';
					a--;
					ans += 'R';
					b++;
				}
				ans += 'D';
				if (a != n-1) {
					ans += 'D';
					for (int i = x + 2; i <= n; i++) {
						for (int j = 1; j < m; j++) {
							if (i % 2) ans += 'L';
							else ans += 'R';
						}
						if (i < n) ans += 'D';
					}
				}
			}

		}
		else if (x % 2 == 0) {
			for (int i = 1; i < x-1; i++) {
				for (int j = 1; j < m; j++) {
					if (i % 2) ans += 'R';
					else ans += 'L';
				}
				ans += 'D';
			}

			int a = x-1, b = 1;
			
			while (b < m) {
				if (b == y) {
					ans += 'R';
					b++;
				}
				if (b == m) break;
				ans += 'D';
				a++;
				ans += 'R';
				b++;
				ans += 'U';
				a--;
				ans += 'R';
				b++;
			}

			ans += 'D';
			if (a != n - 1) {
				ans += 'D';
				for (int i = x + 1; i <= n; i++) {
					for (int j = 1; j < m; j++) {
						if (i % 2) ans += 'L';
						else ans += 'R';
					}
					if (i < n) ans += 'D';
				}
			}
		}
		//cout << "x y: " << x << ' ' << y << '\n';
		cout << ans << '\n';
	}


}

