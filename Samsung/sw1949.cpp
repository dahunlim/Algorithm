#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>
#include <cstring>
using namespace std;
int T, N, K, bong, in;
int map[8][8];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<pair<int, int>> start;
int main(){
    int count = 0;
    cin >> T;
    while(count != T){
        int result = 0;
        bong = 0;
        cin >> N >> K;
        for(int i=0; i<N; i++) for(int j=0; j<N; j++) {
            cin >> in;
            map[i][j] = in;
            if(in > bong){
                start.clear();
                start.push_back(make_pair(i,j));
                bong = in;
            }
            if(in == bong){
                start.push_back(make_pair(i,j));
            }
        }
        int size = start.size();
        while(size--){
            int sx = start.front().first;
            int sy = start.front().second;
            queue<tuple<int, int, int, int, int, int, int>> q;
            int check[8][8][2] = {};
            int len[8][8][2] = {};    
            q.push(make_tuple(sx, sy, bong, 1, 1, -1, -1));
            check[sx][sy][1] = 1;
            len[sx][sy][1] = 1;
            while(!q.empty()){
                int x = get<0>(q.front());
                int y = get<1>(q.front());
                int now = get<2>(q.front());
                int skil = get<3>(q.front());
                int cnt = get<4>(q.front());
                int px = get<5>(q.front());
                int py = get<6>(q.front());
                q.pop();
                if(cnt > result) result = cnt;
                for(int i=0; i<4; i++){
                    int ax = x + dx[i];
                    int ay = y + dy[i];

                    if(ax < 0 || ax >= N || ay < 0 || ay >= N) continue;
                    if(check[ax][ay][skil] != 0 && len[ax][ay][skil] > cnt + 1) continue;

                    if(map[ax][ay] < now){
                        q.push(make_tuple(ax, ay, map[ax][ay], skil, cnt+1, x , y));
                        check[ax][ay][skil] = 1;
                        len[ax][ay][skil] = cnt + 1;
                    }
                    else{
                        if(map[ax][ay] - now >= 0 && map[ax][ay] - now + 1<= K){
                            if(skil){
                                if(ax == px && ay == py) continue;
                                q.push(make_tuple(ax, ay, now-1, 0, cnt+1, x, y));
                                len[ax][ay][skil] = cnt + 1;
                        }
                    }
                    }
                }
            }
            start.erase(start.begin());
        }
        count++;
        cout << "#" << count << " " <<result <<"\n";
    }
    return 0;
}