#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
#define int long long


int gcd(int a, int b){
	if(a == 0) return b;
	else return gcd(b % a, a);
}

signed main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	vector<int>x(n + 1), y(n + 1);

	for(int i = 1; i <= n; i++){
		cin >> x[i];
	}

	for(int i = 1; i <= n; i++){
		cin >> y[i];
	}


	int xx = 1e9; int yy = 1;
	for(int i = 1; i <= n; i++){
		if(yy * x[i] < xx * y[i]) {
			xx = x[i]; yy = y[i];
		}
	}
	
	int g = gcd(xx, yy);

	yy /= g; xx /= g;
	
	vector<bool> b(n + 1);
	for(int i = 1; i <= n; i++){
		if(yy * x[i] == xx * y[i]){
			b[i] = 1;
		}
	}


	int max_len = 1;
	for(int i = 1; i <= n; i++){
		if(!b[i]) continue;
		int j = i;
		while(j <= n && b[j] == 1)j++;
		j--;
		max_len = max(max_len, j - i + 1);
		i = j;
	}

	cout << yy << ' ' << xx << '\n';
	cout << max_len;


}





