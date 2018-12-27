#include <iostream>
using namespace std;
int x;
int len = 64;
int count = 0;
int main(){
    cin >> x;
    while(x>0){ 
        if(len > x) len /= 2;
        else count++, x = x - len;
    }
    cout << count;
    return 0;
}