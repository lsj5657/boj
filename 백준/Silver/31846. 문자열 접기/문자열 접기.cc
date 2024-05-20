#include<bits/stdc++.h>
using namespace std;

int func(string t, int len){
	string l = t.substr(0, len);
	string r = t.substr(len, t.length());

	//cout << "t len: " << t << ' ' << len << '\n';
	//cout << "l r: " << l << ' ' << r << '\n';


	reverse(r.begin(), r.end());
	while(l.length() < r.length()){
		l = '1' + l;
	}

	while(r.length() < l.length()){
		r = '1' + r;
	}

	//cout << "l r: " << l << ' ' << r << '\n';
	int ret = 0;
	for(int i = 0; i < l.length(); i++){
		if(l[i] == r[i]) ret++;
	}

	return ret;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	string s;
	cin >> n >> s;

	int q;
	cin >> q;
	while(q--){
		int l, r;
		cin >> l >> r;
		l--; r--;

		int len = r - l + 1;

		string t = s.substr(l, len);


		int ans = 0;
		for(int i = 1; i < len; i++)
			ans = max(ans, func(t, i));

		cout << ans << '\n';
	}

}