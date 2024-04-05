#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	

	string s; cin >> s;
	int n = s.length();

	bool pal = 1;
	for(int i = 0; i < n / 2; i++){
		if(s[i] != s[n - 1 - i]) pal = 0;
	}

	if(!pal){
		cout << n;
	}
	else{
		set<char> st(s.begin(), s.end());
		if(st.size() == 1){
			cout << -1;
		}
		else{
			cout << n - 1;
		}

	}


}



