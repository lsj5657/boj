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
#include <iomanip>
#include <map>
using namespace std;
#define int long long
#define ld long double



int w[200006], pref[200006];

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);


    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> w[i];
        pref[i] = pref[i - 1] + w[i];
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        int l = max(i - k, 1ll);
        int r = min(i + k, n);

        int d = r - l + 1;
        int cur = pref[l - 1] + d * w[i];
        if(r < n){
            cur += pref[n] - pref[r];
        }

        ans = max(ans, cur);

    }

    cout << ans;




}




