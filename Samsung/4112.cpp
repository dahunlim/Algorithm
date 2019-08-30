// 4112. 이상한 피라미드 탐험
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
int T, a, b, cnt;
int map[141];
int main() {
    /*
    1
    2 3
    4 5 6
    7 8 9 10
    */
    int sum = 1;
    for(int i=1; i<=141; i++) {
        map[i-1] = sum;
        sum += i;
    }
    cin >> T;
    for(int tc=1; tc<=T; tc++) {
        int ax, ay, bx, by;
        cin >> a >> b;
        
        if(a == b) cout << "#" << tc << " 0" << endl;
        else {
            for(int i=0; i<141; i++) {
                if(map[i] <= a) {
                    ax = i; 
                }
            }

            for(int i=0; i<141; i++) {
                if(map[i] <= b) {
                    bx = i; 
                }
            }
            
            ay = a - map[ax];
            by = b - map[bx];

            int xdiff = abs(ax - bx);
            int ydiff = abs(ay - by);
            int addNum = 0;
            if ((ax < bx && ay> by) || (ax > bx && ay < by)) {
                addNum = min(xdiff, ydiff);
            }
            
            cout << "#" << tc << " ";
            if (xdiff < ydiff) cout << ydiff + addNum << endl;
            else cout << xdiff + addNum << endl;
        }
    }
    return 0;
}