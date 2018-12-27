#include <iostream>
#include <cstring>
using namespace std;
int T, N, M, a, b, result;
int combi[1<<20] = {};
void check(int now, int type){
    if(combi[now] == 1){
        return;
    }
    if(type == N){
        combi[now] = 1;
        return;
    }
    if((now & (1 << type)) == 0){//재료추가
        check(now | (1 << type), type);
    }
    check(now, type + 1); //선택
}
int main(){
    cin >> T;
    for(int i=1; i<=T; i++){
        memset(combi, 0, sizeof(combi));
        result = 0;
        cin >> N >> M;
        for(int j=0; j<M; j++){
            cin >> a >> b;
            int no = (1 << (a - 1)) | (1 << (b - 1));
            check(no, 0); 
        }

        for(int j=0; j<(1<<N); j++){
            if(combi[j] == 0) result++;
        }

        cout << "#" << i << " " << result << endl;
    }
    return 0;
}