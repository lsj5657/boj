#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;
#define int long long



int a[2000006];


signed main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);




	int n;
	cin >> n;

	for(int i = 1; i <= n; i++){
		int x; cin >> x;
		a[x]++;
	}

	int mx = 0;
	for(int i = 1; i <= 2000000; i++){

		int cnt = 0;
		for(int j = i; j <= 2000000; j += i){
			if(a[j])cnt += a[j];
			
		}

		if(cnt >= 2) mx = max(mx, cnt*i);
		
	}

	cout << mx;

	

}

