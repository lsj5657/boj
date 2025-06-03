#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;


signed main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	int L, K, C;
	cin >> L >> K >> C;

	vector<int> pos;
	for(int i = 1; i <= K; i++){
		int x; cin >> x;
		pos.push_back(x);
	}

	sort(pos.begin(), pos.end());
	unique(pos.begin(), pos.end());
	K = pos.size();
	pos.push_back(0); 
	sort(pos.begin(), pos.end());
	if(pos.back() != L)pos.push_back(L);
	else K--;



	//for(auto w : pos) cout << w << ' ';
	//cout << '\n';



	int ans1 = 1e9; int ans2 = -1;
	int lo = 1; int hi = 1e9;
	while(lo <= hi){
		int mid = (lo + hi) / 2;
		bool ok = 1;
		for(int i = 0; i <= K; i++){
			if(pos[i + 1] - pos[i] > mid)ok = 0;
		}

		if(!ok) {
			lo = mid + 1;
			continue;
		}

		int suff = L; int cnt = 0;
		int first = 1e9; int max_len = 0;
		for(int i = K; i >= 1; i--){
			if(suff- pos[i -1] > mid){
				max_len = max(max_len, suff - pos[i]);
				suff = pos[i];
				cnt++;
				first = pos[i];
			}
		}
		max_len = max(max_len, suff);


		//cout << "mid cnt: " << mid << ' ' << cnt << '\n';
		//cout << "max_len: " << max_len << '\n';


		if(cnt > C){
			lo = mid + 1;
			continue;
		}
		else{
			if(cnt < C){
				first = pos[1];
			}
			hi = mid - 1;
			if(max_len == ans1){
				ans2 = min(ans2, first);
			}
			else if(max_len < ans1){
				ans1 = max_len;
				ans2 = first;
			}
		}

	}

	cout << ans1 << ' ' << ans2;


}





