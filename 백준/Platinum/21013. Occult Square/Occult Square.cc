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
using namespace std;




signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> board(n + 1, vector<int>(n + 1));

    if(n < 5) cout << -1;
    else{
        int m = (n / 2 + 1);
        board[m][m] = n;
        for(int i = 2; i < m; i++){
            board[i - 1][i] = n;
        }


        for(int i = m + 1; i < n; i++){
            board[i+1][i] = n;
        }

        board[m - 1][1] = board[m + 1][n] = 2;
        board[m + 1][1] = board[m - 1][n] = n-2;


        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }


        //for(int i = 1; i <= n; i++){
        //    int sum = 0;
        //    for(int j = 1; j <= n; j++){
        //        sum += board[i][j];
        //    }

        //    //cout << "i sum: " << i << ' ' << sum << '\n';
        //}

        //for(int j = 1; j <= n; j++){
        //    int sum = 0;
        //    for(int i = 1; i <= n; i++){
        //        sum += board[i][j];
        //    }

        //    //cout << "j sum: " << j << ' ' << sum << '\n';
        //}

  


        
    }



}




