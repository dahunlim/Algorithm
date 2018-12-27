#include <iostream>

using namespace std;

int main(){
    int T, N;
    cin >> T;
    while(T--){
        cin >> N;
        int r[101] = {};
        int count = 0;
        for(int i=1; i<=N; i++){
            for(int j=i; j<=N; j+=i){
                if(r[j]) r[j] = 0;
                else r[j] = 1;
            }
        }

        for(int i=1; i<=N; i++){
            if(r[i]) count++;
        }
        cout << count << "\n";
    }
    return 0;
}