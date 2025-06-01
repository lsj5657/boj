#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define int long long


int n, m, k;
int board[15][15];
int a[15][15];
vector<int> tree[15][15];
int dx[8]{-1,-1,-1,0,1,1,1,0};
int dy[8]{-1,0,1,1,1,0,-1,-1};


signed main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);


	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			board[i][j] = 5;
		}
	}

	for(int i = 1; i <= m; i++){
		int x, y, z;
		cin >> x >> y >> z;
		tree[x][y].push_back(z);
	}

	for(int year = 0; year < k; year++){

		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				int cnt = 0;
				int tot = 0;
				sort(tree[i][j].begin(), tree[i][j].end());
				for(auto& age : tree[i][j]){
					if(age <= board[i][j]){
						board[i][j] -= age;
						age++;
					}
					else{
						cnt++;
						tot += age/2;
					}
				}

				while(cnt--){
					tree[i][j].pop_back();
				}
				board[i][j] += tot;
			}
		}

		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				int cnt = 0;
				board[i][j] += a[i][j];
				for(auto age : tree[i][j]){
					if(age % 5 == 0) cnt++;
				}

				if(cnt == 0) continue;

				for(int dir = 0; dir < 8; dir++){
					int nx = i + dx[dir];
					int ny = j + dy[dir];

					if(nx<1 || nx>n || ny<1 || ny>n) continue;

					
					for(int t = 0; t < cnt; t++){
						tree[nx][ny].push_back(1);
					}
					
				}
			}
		}

		/*cout << "year: " << year << '\n';
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){

				cout << tree[i][j].size() << ' ';
			}
			cout << '\n';
		}
		cout << '\n';*/
	}


	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			ans += tree[i][j].size();
		}
	}

	cout << ans;
	

}

