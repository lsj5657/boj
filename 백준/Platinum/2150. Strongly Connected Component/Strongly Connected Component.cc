#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

int id, d[MAX];
bool finished[MAX];
vector <int > a[MAX];
vector<vector<int>> SCC;
stack <int > s;


int dfs(int x) {
	d[x] = ++id;
	s.push(x);

	int parent = d[x];
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (d[y] == 0) parent = min(parent, dfs(y));
		else if (!finished[y]) parent = min(parent, d[y]);
	}

	if (parent == d[x]) {
		vector<int> scc;
		while (true) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if (t == x) break;
		}
		SCC.push_back(scc);
	}
	return parent;
}

bool compare(vector<int> a, vector<int> b) {
	return a[0] < b[0];
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
	}

	for (int i = 1; i <= n; i++) {
		if (d[i] == 0) dfs(i);
	}
	cout << SCC.size() << '\n';
	for (int i = 0; i < SCC.size(); i++) {
		sort(SCC[i].begin(), SCC[i].end());
	}
	sort(SCC.begin(), SCC.end(), compare);
	for (int i = 0; i < SCC.size(); i++) {
		
		for (int j = 0; j < SCC[i].size(); j++) {
			cout << SCC[i][j] << ' ';
		}
		cout << "-1\n";
	}
}