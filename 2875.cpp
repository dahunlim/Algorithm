#include <iostream>

using namespace std;
int N, M, K;
int main(){
    cin >> N >> M >> K;
    int rest = 0;
    int rest2 = 0;
    if(M+N <= K){cout << 0; return 0;}
    if(N >= M*2){
        rest = N - (M * 2);
        if(rest >= K){
            cout << M;
        }
        else{
            rest2 = K - rest;
            if((rest2 % 3) != 0){
                cout << M - (rest2 / 3) - 1;
            }
            else{
                cout << M - (rest2 / 3);
            }
        }
    }
    else{
        rest = M - (N / 2);
        if(rest >= K){
            cout << N/2;
        }
        else{
            rest2 = K - rest;
            if((rest2 % 3) != 0){
                cout << (N / 2) - (rest2 / 3) - 1;  
            }
            else{
                cout << (N / 2) - (rest2 / 3);
            }
        }
    }

    return 0;
}