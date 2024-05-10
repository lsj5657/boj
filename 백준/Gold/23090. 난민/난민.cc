#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double

int n;

signed main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;

	int xsum = 0;
	priority_queue<int> s;
	priority_queue<int,vector<int>,greater<int>> b;
	int ysum = 0;

	for(int i = 1; i <= n; i++){
		int x, y;
		cin >> x >> y;
		xsum += abs(x);

		int dif;
		if(s.empty()){
			s.push(y);
		}
		else if(s.top() < y){
			if(s.size() == b.size()){
				ysum += abs(y - s.top());
				b.push(y);
				dif = abs(b.top() - s.top());
				ysum += s.size() * dif;
				ysum -= b.size() * dif;
				s.push(b.top());
				b.pop();
			}
			else{
				ysum += abs(y - s.top());
				b.push(y);
			}
		}
		else{
			if(s.size() == b.size()){
				ysum += abs(y - s.top());
				s.push(y);
			}
			else{
				ysum += abs(y - s.top());
				s.push(y);

				int t = s.top(); s.pop();
				dif = abs(s.top() - t);
				ysum -= s.size() * dif;
				ysum += (b.size()+1) * dif;
				b.push(t);
			}
		}





		int tar = s.top();

		/*cout << "i: " << i << '\n';
		cout << "neg: " << neg << ' ' << negcnt << '\n';
		cout << "pos: " << pos << ' ' << poscnt << '\n';
		cout << "xsum tar :" << xsum << ' ' << tar << '\n';
		cout << "ysum: " << ysum << '\n';*/
		

		//cout << s.size() << ' ' << b.size() << '\n';
		int ans = ysum + xsum;
		//cout << "y sum: " << tar << ' ' << ans << '\n';

		cout << tar << ' ' << ans << '\n';
	}

	
}
