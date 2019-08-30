#include <iostream>
#include <cstring>
using namespace std;
int N, cnt, sum;
int val[101];
int chk[10001];

int main() {
    int T;
    cin >> T;
    for(int tc=1; tc<=T; tc++){
        memset(val, -1, sizeof(val));
        memset(chk, 0, sizeof(chk));
        cnt = 0;
        sum = 0;

        cin >> N;
        for(int i=0; i<N; i++){
            cin >> val[i];
            sum += val[i];
        }
        chk[0] = 1;

        for(int i=0; i<N; i++){
            for(int j=sum; j>=0; j--){
                if(chk[j]){
                    chk[j + val[i]] = 1;
                }
            }
        }

        for(int i=0; i < 10001; i++){
            if(chk[i]) cnt += 1;
        }
        cout << "#" << tc << " " << cnt << endl;
    }

    return 0;
}