#include <bits/stdc++.h>
using namespace std;

#define number 100001

const int INF = 0x3f3f3f3f;
int  arr[100001];
int tree[4 * number];

int  init(int start, int end, int node) {
	if (start == end) return tree[node] = arr[start];
	int mid = start + (end - start) / 2;
	return tree[node] = min(init(start, mid, node * 2),init(mid + 1, end, node * 2 + 1));
}

int mini(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return INF;
	if (left <= start && end <= right) return tree[node];
	int mid = start + (end - start) / 2;
	return min(mini(start, mid, node * 2, left, right) ,mini(mid + 1, end, node * 2 + 1, left, right));
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init(0, n - 1, 1);
	while (m--) {
		int a, b;
		cin >> a >> b;
		cout << mini(0, n - 1, 1, a - 1, b - 1) << '\n';
	}
}