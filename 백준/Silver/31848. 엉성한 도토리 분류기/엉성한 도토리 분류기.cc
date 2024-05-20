#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);


	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	int q;
	cin >> q;
	vector<pair<int, int>> v;

	for(int i = 0; i < q; i++){
		int x; cin >> x;
		v.push_back({x,i});
	}

	sort(v.begin(), v.end());

	vector<int> ans(q);

	int st = 0;
	for(int i = 0; i < v.size(); i++){
		int x, idx;
		tie(x, idx) = v[i];

		x -= st;

		while(x > a[st] && st < n){
			st++;
			x--;
		}

		ans[idx] = st + 1;
	}

	for(auto w : ans) cout << w << ' ';

}