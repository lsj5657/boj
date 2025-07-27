#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
#define int long long



signed main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	string s, t;
	cin >> s >> t;

	vector<int> alp(26);
	for(int i = 0; i < s.length(); i++){
		alp[s[i] - 'a'] = 1;
	}


	for(auto w : t){
		if(alp[w - 'a']) continue;
		cout << w;
	}

}





