#include <bits/stdc++.h>
using namespace std;

int n;
int a[1001];
int d[1001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	
	for (int i = 1; i <= n; i++) {
		d[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i]) {
				d[i] = max(d[j] + 1, d[i]);
			}
		}
	}
	cout << *max_element(d, d + n + 1);
}
