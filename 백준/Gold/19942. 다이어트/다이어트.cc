#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
int mp, mf, ms, mv;

int p[16], f[16], s[16], v[16];
int cost[16];
int arr[16];
int ans = 1e9;
set<int> answers;

void func(int k){
	if(k == n){
		int pp = 0, ff = 0, ss = 0, vv = 0, c = 0;
		set<int> st;
		for(int i = 0; i < n; i++){
			if(arr[i]) {
				pp += p[i]; ff += f[i]; ss += s[i]; vv += v[i];
				c += cost[i];
				st.insert(i + 1);
			}
		}

		if(pp >= mp && ff >= mf && ss >= ms && vv >= mv){
			if(c < ans){
				ans = c;
				answers = st;
			}
			else if (c==ans){
				if(st < answers) answers = st;
			}
		}

		return;
	}

	for(int i = 0; i < 2; i++){
		arr[k] = i;
		func(k + 1);
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	cin >> mp >> mf >> ms >> mv;
	for(int i = 0; i < n; i++){
		cin >> p[i] >> f[i] >> s[i] >> v[i] >> cost[i];
	}

	func(0);

	if(ans == 1e9) ans = -1;

	cout << ans << '\n';
	for(auto w : answers) cout << w << ' ';

}



