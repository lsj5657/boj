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


vector<int> nums;



signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    
    int n = s.length();

    for(int i = 0; i < s.length(); i++){
        int j = i + 1;

        while(j < n){
            if('0' <= s[j] && s[j] <= '9') j++;
            else break;
        }
        j--;

        string t = "";
        for(int k = i; k <= j; k++){
            t += s[k];
        }
        nums.push_back(stoll(t));

        i = j;
    }

    int sum = 0;
    for (int i=0; i<nums.size(); i++){
        sum += nums[i];
    }

    if(nums.size() == 1){
        string t = to_string(nums[0]);
        int mx = 0;
        for(int j = 0; j < (int)t.size(); j++) {
            string x = t;
            x.erase(x.begin() + j);
            mx = max(mx, stoll(x));
        }
        cout << mx;
        return 0;
    }

    int mx = 0;
    for(int i = 1; i < nums.size(); i++){
        string l = to_string(nums[i - 1]);
        string r = to_string(nums[i]);

        if(nums[i] > 0){
            string lr = l + r;
            int diff = stoll(lr) - (nums[i - 1] + nums[i]);
            mx = max(mx, diff);

        }
        else{
            string lr = l + r.substr(1);
            int diff= stoll(lr) - (nums[i - 1] + nums[i]);
            mx = max(mx, diff);

            for(int j = 1; j < r.length(); j++){
                string x = r;
                x.erase(x.begin() + j);
                diff = (nums[i - 1] + stoll(x)) - (nums[i - 1] + nums[i]);
                mx = max(mx, diff);
            }
        }
    }


    cout << sum + mx;






}




