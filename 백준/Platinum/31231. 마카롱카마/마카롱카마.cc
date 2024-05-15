#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;

	vector<int> a(n);
	vector<pair<int, int>> v;
	vector<int> cnt(10);
	for(int i = 0; i < s.length(); i++){
		a[i] = s[i] - '0';
		cnt[a[i]]++;
	}

	vector<int> b(n);
	for(int num = 9; num >= 1; num--){
		for(int i = 0; i < n/2; i++){
			if(b[i]) continue;
			int need = 2;
			if(a[i] == num) need--;
			if(a[n - 1 - i] == num) need--;

			if(need <= 1){
				b[i] = b[n - 1 - i] = num;
				cnt[num] -= need;
			}
		}

		for(int i = 0; i < n / 2; i++){
			if(!b[i] && cnt[num] >= 2){
				b[i] = b[n - 1 - i] = num;
				cnt[num] -= 2;
			}
		}

		if(n % 2 && !b[n / 2] && cnt[num]){
			b[n / 2] = num;
		}
	}

	for(int i = 0; i < n; i++) cout << max(a[i], b[i]);
}