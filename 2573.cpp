#include <iostream>
#include <deque>
#include <queue>
using namespace std;
int N, M;
int map[300][300];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
typedef struct cordi{
    int x;
    int y;
} cord;

int main(){
    int flag = 1;
    deque<cord> dq;
    cin >> N >> M;
    for(int i=0; i<N; i++) for(int j=0; j<M; j++) {
        cin >> map[i][j];
        if(map[i][j] != 0) dq.push_back(cord{i, j});
    }
    while(flag){
        bool check[300][300];
        size = dq.size()
        for(int i=0; i<size; i++){
            int nx = dq.front().x;
            int ny = dq.front().y;
            dq.pop_front();
            for(int j=0; j<4; j++){
                int ax = nx + dx[j];
                int ay = ny + dy[j];

                if(map[ax][ay] == 0) map[nx][ny] -= 1;
            }
            if(map[nx][ny] > 0) dq.push_back(cord{nx, ny});
        }
        queue<cord> q;
        q.push(dq.front());
        while(!q.empty()){
                        
        }
    }
    return 0;
}