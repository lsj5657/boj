#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cstring>
#include <string>
#include <cstdlib>
#include <random>
using namespace std;
#define int long long


signed main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	int n, s, e;
	cin >> n >> s >> e;

	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	int k;
	cin >> k;

	if(s > e) swap(s, e);

	int mn = abs(s - e) + 1;

	int mx = 0;


	for(int i = s; i <= e; i++) mx += a[i];


	if(a[s] >= 2){
		int idx = s;
		while(idx >= 1 && a[idx] >= 2) idx--;
		if(idx == 0) idx++;
		for(int i = idx; i < s; i++)mx += a[i];
	}

	if(a[e] >= 2){
		int idx = e;
		while(idx <= n && a[idx] >= 2) idx++;
		if(idx == n+1) idx--;

		for(int i = e+1; i <= idx; i++){
			mx += a[i];
		}
	}

	


	if(mn <= k && k <= mx){
		cout << 1;
	}
	else cout << 0;




}



