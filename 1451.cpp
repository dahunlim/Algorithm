#include <iostream>
using namespace std;
int N, M, s1, s2, s3, temp, result;
int map[100][100];
long sum[100][100];
void square(){
    for(int i=0; i<M; i++){
        for(int j=0; j<=i; j++){
            sum[0][i] += map[0][j];
        }
    }
    for(int k=1; k<N; k++){
        for(int i=0; i<M; i++){
            for(int j=0; j<=i; j++){
                sum[k][i] += map[k][j];
            }
            sum[k][i] += sum[k-1][i];
        }
    }
    return ;
}
int solve(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            for(int k=0; k<4; k++){
                if(k==0){ //case 1
                    if(i == N-1) continue;
                    temp = sum[i][j] * (sum[N-1][M-1]-sum[i][M-1]) * (sum[i][M-1]-sum[i][j]);
                }
                else if(k==1){ //case 2
                    if(j == M-1) continue;
                    temp = sum[i][j] * (sum[N-1][M-1] - sum[N-1][j]) * (sum[N-1][j] - sum[i][j]);
                }
                else if(k==2){ //case 3
                    if((i == N-1) || (j == M-1)) continue;
                    temp = sum[i][M-1] * (sum[N-1][j] - sum[i][j]) * (sum[N-1][M-1] - (sum[N-1][j] - sum[i][j]) - (sum[i][M-1]));
                }
                else{ //case 4
                    if((i == N-1) || (j == M-1)) continue;
                    temp = sum[N-1][j] * (sum[i][M-1] - sum[i][j]) * (sum[N-1][M-1] - (sum[i][M-1] - sum[i][j]) - (sum[N-1][j]));
                }
                if(temp > result) result = temp;
            }
        }
    }
    return result;
}
int main(){ 
    cin >> N >> M;
    for(int i=0; i<N; i++) for(int j=0; j<M; j++){
        scanf("%1d", &map[i][j]);
    }
    square();
    if(N == 1 || M == 1){
        if(N == 1){
            for(int i=0; i<M-2; i++) for(int j=i+1; j<M-1; j++){
                s1 = sum[N-1][i];
                s2 = sum[N-1][j] - s1;
                s3 = sum[N-1][M-1] - sum[N-1][j];
                temp = s1 * s2 * s3;
                if(temp > result) result = temp;
            }
        }
        else{
            for(int i=0; i<N-2; i++) for(int j=i+1; j<N-1; j++){
                s1 = sum[i][M-1];
                s2 = sum[j][M-1] - s1;
                s3 = sum[N-1][M-1] - sum[j][M-1];
                temp = s1 * s2 * s3;
                if(temp > result) result = temp;
            }
        }
        cout << result <<endl;
    }
    else{
        cout << solve();
    }
    return 0;
}