#include <bits/stdc++.h>
using namespace std;
#define int long long


void fast_io(){
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
}

int n;

signed main() {
	fast_io();

	cin >> n;
	vector<int> a(n + 1);
	int t = n;
	

	if(n % 2) a[n / 2 + 1] = 1;

	for(int i = 1; i <= n / 2; i++){
		if(i % 2){
			a[n + 1 - i] = t--;
			a[i] = t--;
		}
		else{
			a[i] = t--;
			a[n + 1 - i] = t--;
		}
	}

	for(int i = 1; i <= n; i++) cout << a[i] << ' ';

}


