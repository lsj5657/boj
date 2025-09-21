#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100];
bool en;

bool check(int idx, int x) {
	arr[idx] = x;
	int tmp = (idx+1) / 2;

	for (int len = 2; len <= tmp; len++) {
		bool tf = true;
		for (int i = idx + 1 - len; i < idx + 1; i++) {
			if (arr[i] != arr[i - len]) {
				tf = false;
				break;
			}
		}
		if (tf) return false;
	}
	arr[idx] = 0;
	return true;
}

void func(int k) {
	if (k == n) {
		if (en)return;
		for (int i = 0; i < k; i++) {
			cout << arr[i];
		}
		en = true;
		return;
	}
	if (!en) {
		for (int i = 1; i <= 3; i++) {
			if (i == arr[k - 1]) continue;
			if (check(k, i)) {
				arr[k] = i;
				func(k + 1);
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	func(0);
}