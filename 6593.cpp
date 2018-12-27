#include <iostream>
#include <queue>
using namespace std;
int L, R, C;
char input;
char map[30][30][30];
bool check[30][30][30];
typedef struct cordi{
    int x;
    int y;
    int z;
    int time = 0;
} pos;

int main(){
    pos start;
    pos end;
    queue<pos> q1;
    cin >> L >> R >> C;
    for(int i=0; i<L; i++) for(int j=0; j<R; j++) for(int k=0; k<C; k++){
        cin >> input;
        if(input == 'S')start({R, C, L});
        if(input == 'E')end({R, C, L});
    }
    
    q1.push(start);
    while(!q1.empty()){
        int nx = q1.front().x;
        int ny = q1.front().y;
        int nz = q1.front().z;

    }
    return 0;
}