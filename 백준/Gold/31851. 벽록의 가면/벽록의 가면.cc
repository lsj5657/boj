#include<bits/stdc++.h>
using namespace std;
#define int long long
#define X first
#define Y second
#define pii pair<int,int>

pii p;

int ccw(pair<int, int> a, pair<int, int> b, pii c){
	int ret = a.X * b.Y + b.X * c.Y + c.X * a.Y - (a.X * c.Y + b.X * a.Y + c.X * b.Y);
	if(ret) ret /= abs(ret);
	return ret;
}

int dist(pii a, pii b){
	return abs(a.X - b.X) + abs(a.Y - b.Y);
}

bool cmp1(pii a, pii b){
	if(a.Y == b.Y) return a.X < b.X;
	else return a.Y < b.Y;
}
bool cmp2(pii a, pii b){
	int c = ccw(p, a, b);
	if(c == 0) return dist(p, a) < dist(p, b);
	else return  c > 0;
}

int func(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int>d){
	vector<pair<int, int>> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);




	sort(v.begin(), v.end(), cmp1);
	p = v[0];
	sort(v.begin() + 1, v.end(), cmp2);

	//cout << "v: " << '\n';
	for(int i = 0; i < v.size(); i++){
		//cout << v[i].first << ' ' << v[i].second << '\n';
	}
	stack<int> stk;
	stk.push(0);
	stk.push(1);


	for(int i = 2; i < 4; i++){
		while(stk.size() >= 2){
			int f, s;
			f = stk.top(); stk.pop();
			s = stk.top();

			if(ccw(v[s], v[f], v[i]) > 0){
				stk.push(f);
				break;
			}
		}
		stk.push(i);
	}

	//cout << "size: " << stk.size() << '\n';
	if(stk.size() == 4) return 1;
	else return 0;
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);


	int n;
	cin >> n;
	vector<pair<int, int>> v(n);

	for(int i = 0; i < n; i++){
		cin >> v[i].first >> v[i].second;
	}

	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			for(int k = j + 1; k < n; k++){
				for(int h = k + 1; h < n; h++){
					ans += func(v[i], v[j], v[k], v[h]);
				}
			}
		}
	}

	cout << ans;


}