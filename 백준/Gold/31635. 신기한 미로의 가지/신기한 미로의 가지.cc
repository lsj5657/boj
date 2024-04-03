#include <bits/stdc++.h>
using namespace std;
#define int long long


void fast_io(){
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
}

int n;

signed main() {
	fast_io();
	
	cin >> n;
	vector<pair<int, int>> ans;
	map<int, int> mp;

	int cur = 1;
	set<int> st;
	st.insert(1);

	while(ans.size() < n - 1){
		cout << "maze" << endl;
		int k; cin >> k;
		if(st.count(k)){

			cout << "gaji " << cur << endl;
			cin >> cur;
			cout << "gaji " << mp[cur] << endl;
			cin >> cur;
		}
		else{
			st.insert(k);
			mp[k] = cur;
			ans.push_back({cur,k});
			cur = k;
		}
	}

	sort(ans.begin(), ans.end());
	cout << "answer" << endl;
	for(auto w : ans) cout << w.first << ' ' << w.second << endl;

}


