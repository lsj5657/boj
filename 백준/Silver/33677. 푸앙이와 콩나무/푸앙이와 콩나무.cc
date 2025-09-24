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

int n;

int dp[1000006];
int dist[1000006];
vector<pair<int,int>> adj[1000006];

int func(int cur){
    if(cur > n) return 1e9;
    if(cur == n) return 0;

    int& ret = dp[cur];
    if(ret != -1) return ret;

    ret = 1e9;

    int c1 = 1 + func(cur + 1);
    int c2 = 1 + func(cur * 3);
    int c3 = 1 + func(cur * cur);

    ret = min({ret,c1,c2,c3});

    if(ret == c1){
        if(cur +1<=n)adj[cur].push_back({1, cur+1});
    }

    if(ret == c2){
        if(cur * 3 <= n)adj[cur].push_back({3, cur*3});
    }

    if(ret == c3){
        if(cur * cur <= n)adj[cur].push_back({5, cur*cur});
    }



    return ret;
}



signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin >> n;

    for(int i = 0; i <= n; i++){
        dp[i] = -1;
        dist[i] = 1e9;
    }

    int day = func(0);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 0});
    dist[0] = 0;

    while(!pq.empty()){
        int d, cur;
        tie(d, cur) = pq.top(); pq.pop();

        if(dist[cur] != d) continue;

        

        for(auto nxt : adj[cur]){
            //cout << "nxt dist: " << nxt.second << ' ' << dist[nxt.second] << '\n';
            if(dist[nxt.second] < d + nxt.first)continue;
            dist[nxt.second] = d + nxt.first;
            pq.push({dist[nxt.second], nxt.second});
        }
    }

    //for(int i = 0; i <= n; i++){
    //    cout << "i: " << i << '\n';
    //    for(auto nxt : adj[i]) cout << nxt.first << ' ' << nxt.second << '\n';
    //    cout << '\n';
    //}

    cout << day << ' ' << dist[n];







}







