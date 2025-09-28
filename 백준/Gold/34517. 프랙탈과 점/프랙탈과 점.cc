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

int L, k;
int a, b;
int p, q;
bool eps_p, eps_q;


bool chk(int x, int y, int len, int p, int q){
    int x_l = x; int x_r = x + len;
    
    int y_l = y; int y_r = y + len;

    if(x_r == p && eps_p) return 0;
    if(y_r == q && eps_q) return 0;

    if(x_l <= p && p <= x_r && y_l <= q && q <= y_r) return 1;
    else return 0;


}




int func(int a, int b, int l, int len, int p, int q){

    if(l == L){
        return chk(a, b, len, p, q);
    }

    int ret = 0;

    int new_len = len / 3;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i == 1 && j == 1) continue;
            int x = a + new_len * i;
            int y = b + new_len * j;

            if(chk(x, y, new_len, p, q)){
                ret |= func(x, y, l + 1, new_len, p, q);

            }

        }
    }

    return ret;
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--){

        cin >> a >> b >> L >> k;

        string s1;
        cin >> s1;

        int len = s1.length();
        p = stoll(s1.substr(0, len - 4));

        
        eps_p = stoi(s1.substr(len - 3, 3));
        if(s1[0] == '-' && eps_p) p--;

        string s2;
        cin >> s2;

        len = s2.length();
        q = stoll(s2.substr(0, len - 4));

        
        eps_q = stoi(s2.substr(len - 3, 3));
        if(s2[0] == '-' && eps_q) q--;


        //cout << "p q: " << p << ' ' << q << '\n';
        //cout << "epsp epsq: " << eps_p << ' ' << eps_q << '\n';



        len = 1;
        for(int i = 0; i < k; i++) len *= 3;

        cout << func(a, b, 0, len, p, q) << '\n';
    }








}




