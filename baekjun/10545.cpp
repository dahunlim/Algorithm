#include <iostream>
#include <cstring>
#include <string>
using namespace std;
char input[10];
string problem;
string ans;
int count = 0;
int setting[9][4] = {{-1, -1, -1, -1}, {97, 98, 99, -1}, {100, 101, 102, -1}, {103, 104, 105, -1}, {106, 107, 108, -1}, {109, 110, 111, -1}, {112, 113, 114, 115}, {116, 117, 118, -1}, {119, 120, 121, 122}};
int main(){
    for(int i=1; i<10; i++){
        char in;
        cin >> in;
        input[in-49] = i+48;
    }
    cin >> problem;
    int pre = -1;
    for(int i=0; i<problem.length(); i++){
        int flag = 0;
        int now = problem[i];
        for(int j=0; j<9; j++){
            for(int k=0; k<4; k++){
                if(setting[j][k] == now){
                    flag = 1;
                    if(j == pre) ans += '#';
                    for(int l=0; l<=k; l++){
                        ans += input[j];
                    }
                    pre = j;
                    break;
                }
            }
            if(flag) break;
        }
    }
    cout << ans;
    return 0;
}