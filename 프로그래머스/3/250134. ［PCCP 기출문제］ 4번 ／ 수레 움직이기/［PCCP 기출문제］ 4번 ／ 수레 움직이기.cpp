#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <queue>
#include <iostream>
#include <set>

int dx[4]{1,0,-1,0};
int dy[4]{0,1,0,-1};
using namespace std;

map<tuple<vector<vector<int>>, set<pair<int,int>>, set<pair<int,int>>>, bool> vis;

int solution(vector<vector<int>> maze) {
    int n = maze.size();
    int m = maze[0].size();
    int rdx, rdy;
    int bdx, bdy;
    
    set<pair<int,int>> s1, s2;
    for (int i=0; i<n; i++){
        for (int j=0; j<m;j ++){
            if(maze[i][j]==1){
                s1.insert({i,j});
            }
            if(maze[i][j]==2){
                s2.insert({i,j});
            }
            if(maze[i][j]==3){
                rdx=i; rdy=j;
            }
            if(maze[i][j]==4){
                bdx=i; bdy=j;
            }
        }
    }
    
    queue<tuple<vector<vector<int>>, set<pair<int,int>>, set<pair<int,int>>, int> > q;

    q.push({maze,s1, s2, 0});
    vis[{maze,s1,s2}] = true;

    while(!q.empty()){
        vector<vector<int>> cur_maze; int ti;
        set<pair<int,int>> rset, bset;
        tie(cur_maze,rset, bset, ti) = q.front(); q.pop();
        
        int rx=-1, ry=-1, bx=-1, by=-1;
        int rgoal=0, bgoal=0;

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if(cur_maze[i][j]==1){
                    rx=i; ry=j;
                }
                if (cur_maze[i][j]==2){
                    bx=i; by=j;
                }
                if(cur_maze[i][j]==9){
                    rx=i; ry=j;
                    rgoal=1;
                }
                if(cur_maze[i][j]==10){
                    bx=i; by=j;
                    bgoal=1;
                }
            }
        }

        if(rgoal && bgoal){
            return ti;
        }

        for (int dir1=0; dir1<4; dir1++){
            for (int dir2=0; dir2<4; dir2++){
                int nx1= rx+dx[dir1]; int ny1= ry+dy[dir1];
                int nx2= bx+dx[dir2]; int ny2= by+dy[dir2];

                if(rgoal) { nx1=rx; ny1=ry; }
                if(bgoal) { nx2=bx; ny2=by; }

                if(nx1<0 || nx1>=n || ny1<0 || ny1>=m) continue;
                if(nx2<0 || nx2>=n || ny2<0 || ny2>=m) continue;
                if(cur_maze[nx1][ny1]==5 || cur_maze[nx2][ny2]==5) continue;

                if(nx1==nx2 && ny1==ny2) continue; // 같은 칸 이동
                if(nx2==rx && ny2==ry && nx1==bx && ny1==by) continue; // 자리 바꾸기

                if(!rgoal && rset.count({nx1,ny1})) continue;
                if(!bgoal && bset.count({nx2,ny2})) continue;

                vector<vector<int>> tmp = cur_maze;
                tmp[rx][ry]=0;
                tmp[bx][by]=0;
                tmp[rdx][rdy]=3;
                tmp[bdx][bdy]=4;
                tmp[nx1][ny1]=1;
                tmp[nx2][ny2]=2;

                if(nx1==rdx && ny1==rdy) tmp[rdx][rdy]=9;
                if(nx2==bdx && ny2==bdy) tmp[bdx][bdy]=10;

                set<pair<int,int>> new_rset = rset;
                set<pair<int,int>> new_bset = bset;
                if(!rgoal) new_rset.insert({nx1, ny1});
                if(!bgoal) new_bset.insert({nx2, ny2});

                auto new_state = make_tuple(tmp, new_rset, new_bset);
                if(vis[new_state]) continue;
                vis[new_state] = true;
                q.push({tmp, new_rset, new_bset, ti+1});
            }
        }
    }

    return 0;
}
