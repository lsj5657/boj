#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, c;
	cin >> n >> c;

	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		bool tf = true;
		int x; cin >> x;
		for (auto& w : v) {
			if (w.second == x) {
				tf = false;
				w.first++;
				break;
			}
		}
		if (tf) v.push_back({ 1,x });
	}

	stable_sort(v.begin(), v.end(), compare);

	for (auto w : v) {
		while (w.first--) {
			cout << w.second << ' ';
		}
	}
}