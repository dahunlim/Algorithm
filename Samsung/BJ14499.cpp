// 14999 주사위굴리기
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
int N, M, K, x, y;
int ax[4] = {0, 0, -1, 1};
int ay[4] = {1, -1, 0, 0}; //동 서 북 남
int dice[7] = {0, };
int map[21][21];
int main() {
    cin >> N >> M >> x >> y >> K;
    for(int i=0; i<N; i++) for(int j=0; j<M; j++) cin >> map[i][j];
    for(int i=0; i<K; i++) {
        int order;
        cin >> order;
        order--;

        int nx = x + ax[order];
        int ny = y + ay[order];
        if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

        int ndice[7] = {0, };
        if(order==0){
			ndice[3]=dice[1];
			ndice[1]=dice[4];
			ndice[4]=dice[6];
			ndice[6]=dice[3];
			ndice[2]=dice[2];
			ndice[5]=dice[5];
		}
		if(order==1){
			ndice[1]=dice[3];
			ndice[3]=dice[6];
			ndice[6]=dice[4];
			ndice[4]=dice[1];
			ndice[2]=dice[2];
			ndice[5]=dice[5];
		}
		if(order==2){
			ndice[1]=dice[5];
			ndice[5]=dice[6];
			ndice[6]=dice[2];
			ndice[2]=dice[1];
			ndice[3]=dice[3];
			ndice[4]=dice[4];
		}
		if(order==3){
			ndice[1]=dice[2];
			ndice[2]=dice[6];
			ndice[6]=dice[5];
			ndice[5]=dice[1];
			ndice[3]=dice[3];
			ndice[4]=dice[4];
		}

        if(map[nx][ny] == 0) {
            map[nx][ny] = ndice[6];
        } else {
            ndice[6] = map[nx][ny];
            map[nx][ny] = 0;
        }
        cout << ndice[1] << endl;
        
        for(int i=0; i<7; i++) dice[i] = ndice[i];

        x = nx;
        y = ny;

    }    
    return 0;
}