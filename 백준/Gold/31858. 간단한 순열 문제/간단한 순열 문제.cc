#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double




signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		v.push_back({x,i});
	}

	sort(v.begin(), v.end(), greater<>());

	int ans = 0;

	set<int> st;
	for(int i = 0; i < n; i++){
		int x, idx;
		tie(x, idx) = v[i];

		if(st.empty()){
			st.insert(idx);
			continue;
		}

		st.insert(idx);
		auto it = st.find(idx);

		if(it != st.begin()){
			ans++;
		}
		if(it != prev(st.end())){
			ans++;
		}
	}

	cout << ans;




}