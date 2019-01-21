#include <iostream>
#include <queue>
using namespace std;
struct c{int cx, cy, bx, by, cnt;};
int ax[4]={0, 0, 1, -1};
int ay[4]={1, -1, 0, 0};    

int main(){
    int x, y;
    int result = -1;
    int map[10][10] = {};
    char input;
    bool visit[10][10][10][10];
    c R;c O;c cor;
    queue<c> q;

    cin >> x >> y;
    for(int i=0;i<x;i++)for(int j=0;j<y;j++){
        cin >> input;
        if(input == '.'){map[i][j]=0;}
        if(input == 'R'){R.cx=i; R.cy=j;}
        if(input == 'B'){R.bx=i; R.by=j;}
        if(input == 'O'){O.cx=i; O.cy=j;}
        if(input == '#'){map[i][j]=1;}
    }
    R.cnt = 0;
    q.push(R);
    visit[R.cx][R.cy][R.bx][R.by] = true;

    while(!q.empty()){
        
        cor = q.front();q.pop();
        if(cor.cnt > 10){
            result = -1;
            break;
        }
        if(cor.cx == O.cx && cor.cy == O.cy){
            result = cor.cnt;
            break;
        }
        for(int i=0; i<4; i++){
            int nx = cor.cx; int ny = cor.cy;
            int nbx = cor.bx; int nby = cor.by;
            
            //이동
            while(1){
                nx += ax[i]; ny += ay[i];
                if(map[nx][ny] == 1){
                    nx -= ax[i], ny -= ay[i];
                    break; 
                } else if(nx == O.cx && ny == O.cy){
                    break;
                }
            }
            
            while(1){
                nbx += ax[i]; nby += ay[i];
                if(map[nbx][nby] == 1){
                    nbx -= ax[i], nby -= ay[i];
                    break; 
                } else if(nbx == O.cx && nby == O.cy){
                    break;
                }
            }
            if(nbx == O.cx && nby == O.cy) continue;

            //겹쳤을때
            if((nx == nbx) && (ny == nby)){
                if(i==0){//동
                    cor.cy > cor.by ? nby-- : ny--;
                } else if(i==1){//서
                    cor.cy > cor.by ? ny++ : nby++; 
                } else if(i==2){//남
                    cor.cx > cor.bx ? nbx-- : nx--;
                } else{//북
                    cor.cx > cor.bx ? nx++ : nbx++;
                }
            }
            if(!visit[nx][ny][nbx][nby]){
                q.push({nx, ny, nbx, nby, cor.cnt+1});
                visit[nx][ny][nbx][nby] = true;
            }
        }
    }
    cout << result;
    return 0;
}