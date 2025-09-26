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


int a[5000006];

int n;


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    tc = 1;
    while(tc--){

        cin >> n;
        //n = 2 * n + 1;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        sort(a + 1, a + n + 1);


        int l = 0; int r = 0;
        for(int i = n; i > 4; i -= 2){
            r += a[i] - a[i - 1];
        }

        int ans = 1e18;
        for(int i = 1; i + 2 <= n; i+=2){
            int t = l + a[i + 2] - a[i] + r;
            l += a[i + 1] - a[i];
            if(i + 4 <= n){
                r -= a[i + 4] - a[i + 3];
            }
            ans = min(ans, t);
        }

        cout << ans << '\n';



    }






}







