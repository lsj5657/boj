#include <bits/stdc++.h>
using namespace std;

int d[1000001];
int n;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int res = d[i - 1];
		if (i % 2 == 0) res = min(res, d[i / 2]);
		if (i % 3 == 0) res= min(res, d[i/ 3]);
		d[i] = res+1;
	}
	cout << d[n];

}
