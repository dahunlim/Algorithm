#include <iostream>

using namespace std;
int i, o, temp, now;
int main(){
    now = 0, temp = 0;
    for(int j=0; j<4; j++){
        cin >> i >> o;
        now -= i;
        now += o;
        if(now >= temp) temp = now;
    }
    cout << temp;
    return 0;
}