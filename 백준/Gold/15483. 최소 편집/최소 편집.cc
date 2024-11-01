#include <iostream>
#include <vector>
using namespace std;



vector <vector<int>> dp;
string s, t;
int n, m;

int func(const int& i, const int& j) {

	if (i >= n) {
		return m - j;
	}
	if (j >= m) {
		return n - i;
	}

	int& ret = dp[i][j];
	if (ret != -1) return ret;

	ret = 10000;
	if (s[i] == t[j]) {
		ret = min(ret, func(i + 1, j + 1));
	}
	else {

		//�߰�
		if (ret > 1 + func(i , j +1)) {
			ret = 1 + func(i, j + 1);
		}

		//����
		if (ret > 1 + func(i + 1, j + 1)) {
			ret = 1 + func(i + 1, j + 1);
		}
		//����
		if (ret > 1 + func(i + 1, j )) {
			ret = 1 + func(i + 1, j);
		}
	}

	return ret;
}


signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int tc;
	tc=1;
	while (tc--) {
		cin >> s >> t;
		if (s == t) {
			cout << 0 << '\n';
			continue;
		}
		n = s.length(); m = t.length();

		dp = vector <vector<int>>(n , vector<int>(m, -1));

		cout << func(0, 0) << '\n';

	}

}