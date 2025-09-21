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

int n;

ld r_dp[105][105][105];
ld g_dp[105][105][105];
ld b_dp[105][105][105];

ld r_func(int r, int g, int b){
    if(r == 0) return 0;
    if(g == 0) return 0;
    if(b == 0) return 1;

    ld& ret = r_dp[r][g][b];
    if(ret != -1) return ret;

    ret = 0;

    ld tot = r * g + g * b + b * r;
    ret += (b * r / tot) * r_func(r - 1, g, b);
    ret += (r * g / tot) * r_func(r, g - 1, b);
    ret += (g * b / tot) * r_func(r, g, b - 1);


    return ret;
}

ld g_func(int r, int g, int b){
    if(b == 0) return 0;
    if(g == 0) return 0;
    if(r == 0) return 1;

    ld& ret = g_dp[r][g][b];
    if(ret != -1) return ret;

    ret = 0;

    ld tot = r * g + g * b + b * r;
    ret += (b * r / tot) * g_func(r - 1, g, b);
    ret += (r * g / tot) * g_func(r, g - 1, b);
    ret += (g * b / tot) * g_func(r, g, b - 1);


    return ret;
}


ld b_func(int r, int g, int b){
    if(b == 0) return 0;
    if(r == 0) return 0;
    if(g == 0) return 1;

    ld& ret = b_dp[r][g][b];
    if(ret != -1) return ret;

    ret = 0;

    ld tot = r * g + g * b + b * r;
    ret += (b*r / tot) * b_func(r - 1, g, b);
    ret += (r*g / tot) * b_func(r, g - 1, b);
    ret += (g * b/ tot) * b_func(r, g, b - 1);


    return ret;

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;

    cin >> tc;
    while(tc--){
        int r, g, b;
        cin >> r >> g >> b;

        for(int i = 0; i <= r; i++){
            for(int j = 0; j <= g; j++){
                for(int k = 0; k <= b; k++){
                    r_dp[i][j][k] = -1;
                    g_dp[i][j][k] = -1;
                    b_dp[i][j][k] = -1;
                }
            }
        }

        cout << fixed << setprecision(12);

        cout << r_func(r, g, b) << ' ' << g_func(r, g, b) << ' ' << b_func(r, g, b) << '\n';

    }


}




