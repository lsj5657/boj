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

int N, M, K, R, W;
int mx[2];

vector<int> get_val(int l, int r){
    l = max(l, (int)1);
    r = min(r, K);

    if(l > r) return vector<int>();

    int wcnt = r / R;
    int pcnt = r / 2;

    vector<int> cand;
    int cur = 0;
    cur += wcnt * W;
    cur += pcnt * (mx[1] + mx[0]);
    if(r % 2) cur += mx[1];

    cand.push_back(cur);


    for(int i = r; i >= l; i--){
        int t = i % 2;
        cur -= mx[t];
        if(i % R == 0) cur -= W;
        cand.push_back(cur);
    }

    return cand;
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin >> N >> M >> K >> R >> W;

    vector<pair<int, int>> edges;

    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges.push_back({u,v});
    }



    vector<int> p(N);
    for(int i = 0; i < N; i++){
        cin >> p[i];
    }

    int ans = 0;



    for(auto pi : edges){
        int u, v;
        tie(u, v) = pi;

        mx[1] = p[u]; mx[0] = p[v];
        if(mx[1] < mx[0]) swap(mx[1], mx[0]);

        vector<int> cand;

        for(auto w : get_val(1, 5)){
            cand.push_back(w);
        }

        for(auto w : get_val(R - 5, R + 5)){
            cand.push_back(w);
        }

        for(auto w : get_val(2 * R - 5, 2 * R + 5)){
            cand.push_back(w);
        }





        int q = K / R;
        for(auto w : get_val((q - 1)* R - 5, (q - 1)* R + 5)){
            cand.push_back(w);
        }
        for(auto w : get_val(q* R - 5, q* R + 5)){
            cand.push_back(w);
        }

        for(auto w : get_val(K - 5, K)){
            cand.push_back(w);
        }

        int cost = 0;
        for(auto w : cand){
            cost = max(cost, w);
        }
        // cout << "u v: "<< u << ' '<< v << '\n';
        // cout << "p[u] p[v]: "<< p[u] << ' ' << p[v] << '\n';
        // for(auto w:get_val(1,K)){
        //     cout << "w: "<< w << '\n';
        // }

        ans = max(ans, cost);

    }

    cout << ans;







}







