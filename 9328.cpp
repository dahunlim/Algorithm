#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <stdio.h>
using namespace std;
int T, h, w;
string s;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int main(){
    cin >> T;
    while(T--){
        //input
        char map[102][102] = {};
        int check[102][102] = {};
        int key[26] = {};
        int result = 0;
        queue<pair<int, int>> q; //bfs queue
        queue<pair<int, int>> wait; //waiting queue
        cin >> h >> w;
        for(int i=1; i<=h; i++) for(int j=1; j<=w; j++){
            cin >> map[i][j];
            if(map[i][j] == '*') check[i][j] = -1;
        }
        cin >> s;
        for(int i=0; i<s.size(); i++) key[s[i]-97] = 1;
        q.push(make_pair(0, 0));
        //bfs
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(map[x][y] == '$') result++;

            for(int i=0; i<4; i++){
                int ax = x + dx[i];
                int ay = y + dy[i];
                if(ax < 0 || ax > h+1 || ay < 0 || ay > w+1) continue; //outofrange
                if(check[ax][ay] != 0) continue; //wall or visit
                else if(map[ax][ay] >= 65 && map[ax][ay] <= 90){//door
                    if(key[map[ax][ay] - 65] == 1){//have
                        q.push(make_pair(ax,ay));
                        check[ax][ay] = 1;
                    }
                    else{//Not have
                        wait.push(make_pair(ax, ay));
                    }
                }
                else if(map[ax][ay] >= 97 && map[ax][ay] <= 122){//key
                        key[map[ax][ay] - 97] = 1;
                        int keynum = map[ax][ay];
                        int k = wait.size();
                        q.push(make_pair(ax, ay));
                        check[ax][ay] = 1;
                        while(k--){
                            int dx = wait.front().first;
                            int dy = wait.front().second;
                            int door = map[dx][dy] + 32;
                            wait.pop();
                            if(door == keynum){
                                q.push(make_pair(dx, dy));
                                check[dx][dy] = 1;
                            }
                            else{
                                wait.push(make_pair(dx, dy));
                            } 
                        }                    
                }
                else{
                    q.push(make_pair(ax, ay));
                    check[ax][ay] = 1;
                }
            }
        }
        cout << result << "\n";
    }
    return 0;
}