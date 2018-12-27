#include <iostream>
using namespace std;
int N, K, L, R;
int main(){
    R = 1;
    cin >> N >> K >> L;
    K -= 1;
    L -= 1;
    while(1){
        K /= 2;
        L /= 2;
        if(K == L) {
            cout << R;
            break;
        }  
        R++;
    }
    return 0;
}