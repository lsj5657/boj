#include<bits/stdc++.h>
using namespace std;
#define int long long



signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	map<char, int> mp;
	mp['H'] = 1;
	mp['C'] = 12;
	mp['O'] = 16;
	string s;
	cin >> s;

	stack<int> stk;

	for(int i = 0; i < s.length(); i++){
		if(s[i] == '('){
			stk.push(-1);
		}
		else if(s[i] == ')'){
			int num = 0;
			while(!stk.empty()){
				int t = stk.top(); stk.pop();
				if(t == -1) break;
				num += t;
			}
			stk.push(num);
		}
		else if('0' <= s[i] && s[i] <= '9'){
			int t = stk.top() * (s[i] - '0'); stk.pop();
			stk.push(t);
		}
		else{
			stk.push(mp[s[i]]);
		}
	}

	int ans = 0;
	while(!stk.empty()){
		ans += stk.top();
		//cout << stk.top() << ' ';
		stk.pop();
	}
	//cout << '\n';
	cout << ans;
	
}