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
#define ld long double


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--){

        int n;
        cin >> n;
        vector<int> a(n + 1);

        a[1] = 1;
        for(int i = 2; i <= n; i++){
            a[i] = i;
            int sum = a[i - 1] + a[i];
            
            ld d_val = sqrt(sum);
            int i_val = sqrt(sum);

            if(d_val == i_val){
                swap(a[i - 1], a[i - 2]);
            }


        }

        for(int i = 1; i <= n; i++){
            cout << a[i] << ' ';
        }
        cout << '\n';
    }








}




