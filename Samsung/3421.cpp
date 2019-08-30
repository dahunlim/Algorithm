// 3421. 수제 버거 장인
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int combi[400];

int main() {
    int T;
    cin >> T;
    for(int tc=1; tc<=T; tc++) {
        memset(combi, 0, sizeof(combi));
        int N, M;
        cin >> N >> M;
        for(int i=0; i<M; i++) {
            int gredi1, gredi2;
            cin >> gredi1 >> gredi2;
            combi[i] = (1 << gredi1-1) | (1 << gredi2-1);
        }

        int result = 1 << N;
        for(int i=0; i< (1<<N); i++) {
            for(int j=0; j<M; j++) {
                int chk = i & combi[j];
                if(chk == combi[j]) {
                    result--;
                    break;
                }
            }
        }
        cout << "#" << tc << " " << result << endl;
    }
    return 0;
}