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
using namespace std;
#define int long long

const int MAX = 100005;

int n;
int dp[100005];

int a[100006], b[100006];


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while(tc--){
        cin >> n;
        for(int i = 0; i <= 100000; i++){
            dp[i] = 1e9;
            a[i] = b[i] = 0;
        }

        for(int i = 1; i <= n; i++){
            cin >> a[i] >> b[i];
        }

        dp[0] = b[1];
        dp[a[1]] = 0;



       /* for(int j = 0; j <= 30; j++){
            cout << "j dp: " << j << ' ' << dp[j] << '\n';
        }*/
        for(int i = 2; i <= n; i++){

            //cout << "i: " << i << '\n';
            vector<int> buff1(100005, 1e9);
            vector<int> buff2(100005, 1e9);
            for(int j = 0; j <= 100000; j++){
                buff1[j] = dp[j];
                if(buff1[j] != 1e9) buff1[j] += b[i];
            }



            for(int j = 100000; j - a[i] >= 0; j--){
                buff2[j] = min(buff2[j], dp[j - a[i]]);
            }

            for(int j = 0; j <= 100000; j++){
                dp[j] = min(buff1[j], buff2[j]);
            }

            //for(int j = 0; j <= 30; j++){
            //    cout << "j dp: " << j << ' ' << dp[j] << '\n';
            //}
        }


        int ans = 1e9;
        for(int i = 0; i <= 100000; i++){
            int mn = max(i, dp[i]);

            ans = min(ans, mn);
        }

        cout << ans << '\n';
  



    }

}




