#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool compare(vector<vector<int>> key, vector<vector<int>> lock){
    int r1=key.size();
    int c1=key[0].size();
    
    int r2=lock.size();
    int c2=lock[0].size();
    
    int hole=0;
    for (int i=0; i<r2; i++){
        for (int j=0; j<c2; j++){
            if(!lock[i][j]) hole++;
        }
    }
    
    
    for (int x_offset=-r2; x_offset<r1; x_offset++){
        for (int y_offset=-c2; y_offset<c1; y_offset++){
            
            int cnt=0;
            bool ok=1;
            for (int i=0; i<r2; i++){
                for (int j=0; j<c2; j++){
                    int key_x = i+x_offset;
                    int key_y = j+y_offset;
                    if(key_x<0||key_x>=r1 || key_y<0 || key_y>=c1) continue;
                    if(key[key_x][key_y]==0) continue;
                    
                    if(key[key_x][key_y]==1 && lock[i][j]==0)cnt++;
                    if(key[key_x][key_y]==1 && lock[i][j]==1)ok=0;
                }
            }
            if(!ok) continue;
            if(cnt==hole)return true;
            
        }
    }
    
    
    
    
    return false;
}

void print(vector<vector<int>>v){

    for (int i=0; i<(int)v.size(); i++){
        for (int j=0; j<(int)v[i].size(); j++){
            cout << v[i][j] << ' ';
         }
        cout << '\n';
    }
}



bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    
    vector<vector<int>> r1,r2,r3;
    
    
    int n=key.size();
    int m=key[0].size();

    
    for (int j=0; j<m; j++){
        vector<int> v;
        for (int i=n-1; i>=0; i--){

            v.push_back(key[i][j]);
        }
        r1.push_back(v);
    }
    
    for (int i=n-1; i>=0; i--){
        vector<int> v;
        for (int j=m-1; j>=0; j--){
            v.push_back(key[i][j]);
        }
        r2.push_back(v);
    }
    for (int j=m-1; j>=0; j--){
        vector<int> v;
        for (int i=0; i<n; i++){
            v.push_back(key[i][j]);
        }
        r3.push_back(v);
    }
    
    // print(key);
    // cout << '\n';
    // print(r1);
    // cout << '\n';
    // print(r2);
    // cout << '\n';
    // print(r3);
    

    
    bool answer = compare(key,lock) | compare(r1,lock) | compare(r2,lock) | compare(r3,lock);
    return answer;
}