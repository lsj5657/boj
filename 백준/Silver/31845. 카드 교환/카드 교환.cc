#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m;


signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);


	cin >> n >> m;
	vector<int> a(n + 1);

	multiset<int>ms;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		ms.insert(a[i]);
	}

	int c = 0;
	int ans = 0;
	while(!ms.empty()){
		auto it = prev(ms.end());

		int t = *it;

		if(t <= 0){
			break;
		}

		ans += t;
		c++;

		ms.erase(it);
		if(c == m){
			break;
		}

		if(!ms.empty()){
			ms.erase(ms.begin());
		}

	}

	cout << ans;



}