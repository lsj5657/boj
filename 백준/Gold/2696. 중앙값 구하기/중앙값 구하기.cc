#include <bits/stdc++.h>
using namespace std;
#define int long long




signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int> a(n + 1);

		priority_queue<int> mxpq;
		priority_queue<int, vector<int>, greater<int>> mnpq;
		vector<int> v;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
			mxpq.push(a[i]);
			
			if(mxpq.size() - mnpq.size() >= 2){
				mnpq.push(mxpq.top());
				mxpq.pop();
			}

			while(!mxpq.empty() && !mnpq.empty() &&
				mxpq.top() > mnpq.top()){
				int l = mxpq.top(); mxpq.pop();
				int r = mnpq.top(); mnpq.pop();
				mxpq.push(r); mnpq.push(l);
			}

			//cout << "i: " << i << "\n";
			//cout << "l r: " << mxpq.size() << ' ' << mnpq.size() << '\n';

			if(i % 2){
				v.push_back(mxpq.top());
			}
		}

		cout << v.size() << "\n";
		for(int i = 0; i < v.size(); i++){
			if(i && i % 10 == 0) cout << '\n';
			cout << v[i] << ' ';
		}
		

	
	}

}



