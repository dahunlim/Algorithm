#include <iostream>
#include <queue>
using namespace std;
struct c{int t; char d;};
struct m{int length=0; int pass_time=-1;};
int map[100][100] = {0};
int dx[4] = {0, 0, 1, -1}; //동 서 남 북
int dy[4] = {1, -1, 0, 0};
m status[100][100];

int main(){
    int N, K, L, x, y, ans;
    c a;
    queue<c> dir;

    cin >> N; cin >> K;
    for(int i=0; i<K; i++){
        cin >> x >> y;
        map[x-1][y-1] = 1;
    }
    cin >> L;
    for(int i=0; i<L; i++){
        cin >> a.t >> a.d;
        dir.push(a);
    }
    int now = 0; int len = 1; int nx = 0; int ny = 0; int go=0;
    while(1){
        if(dir.front().t == now){
            //방향전환
            switch(go){
                case 0: dir.front().d == 'D' ? go=2 : go=3; break;
                case 1: dir.front().d == 'D' ? go=3 : go=2; break;
                case 2: dir.front().d == 'D' ? go=1 : go=0; break;
                case 3: dir.front().d == 'D' ? go=0 : go=1; break;
            }
            dir.pop();
        }
        
        int ax; int ay;
        ax = nx + dx[go]; ay = ny + dy[go];
        if(ax < 0 || ay < 0 || ax >= N || ay >= N){ //OutofMap
            ans = now + 1;
            break;
        }
        if(status[ax][ay].pass_time != -1)if(now - status[ax][ay].pass_time <= len){ //MeetBody
            ans = now + 1;
            break;
        }
        if(map[ax][ay] == 1){ //Apple
            len++; map[ax][ay] = 0;
        }
        status[ax][ay] = {len, now};
        nx = ax; ny = ay;
        now++;
    }
    cout << ans;
    return 0;
}