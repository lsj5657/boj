#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k;
string s;

int p = 0, c = 0;

signed main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> k;
	cin >> s;
	s = ' ' + s;

	stack<int> stk;
	for(int i = 1; i <= n; i++){
		if(s[i] == 'P') {
			p++;
			stk.push(i);
		}
		else c++;
	}

	for(int i = 1; i <= n; i++){
		//cout << "i: " << i << '\n';
		//cout << "s[i]: " << s[i] << '\n';
		if(s[i] == 'C'){
			if(stk.empty()) break;
			if(!k) break;
			int j = stk.top();
			if(j <= i) break;
			//cout << "j: " << j << '\n';
			swap(s[i], s[j]);
			k--;
			stk.pop();
		}
	}


	//cout << s << '\n';

	int curc = 0, curp = 0;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(s[i] == 'C'){
			ans += (curp * (curp - 1) / 2);
		}
		else{
			curp++;
		}
	}

	cout << ans;
}
