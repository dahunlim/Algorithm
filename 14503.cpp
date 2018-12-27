#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
int map[51][51];
int N, M, r, c, d;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int rx[4] = {-1, 0, 1, 0};
int ry[4] = {0, 1, 0, -1};
int dd[4] = {3, 0, 1, 2};//북동남서
queue<pair<pair<int, int>, int>> q;
int search(int x, int y, int face){
    int count = 0;
    int already = 0;
    q.push(make_pair(make_pair(x, y), face));
    map[x][y] = 2;
    count++;
    while(!q.empty()){
        int a = q.front().first.first;
        int b = q.front().first.second;
        int c = q.front().second;
        q.pop();
        if(map[a+dx[c]][b+dy[c]] == 0){
            q.push(make_pair(make_pair(a+dx[c], b+dy[c]), dd[c]));
            map[a+dx[c]][b+dy[c]] = 2;
            already = 0;
            count++;
        }
        else{
            if(already != 4){
                q.push(make_pair(make_pair(a, b), dd[c]));
                already++;
            }
            else{
                if(map[a+(rx[c]*-1)][b+(ry[c]*-1)] != 1){
                    q.push(make_pair(make_pair(a+(rx[c]*-1), b+(ry[c]*-1)), c));
                    already = 0;
                }
            }
        }
        
    }
    return count;
}
int main(){
    cin >> N >> M;
    cin >> r >> c >> d;
    for(int i=0; i<N; i++) for(int j=0; j<M; j++){
        cin >> map[i][j];
    }
    cout << search(r, c, d);
    return 0;
}