//1808. 지희의 고장난 계산기
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int cal[10];
int make[1000001];
int input, answer;

void solve(int val, int cnt) {
    if(val == 1) {
        answer = min(answer, cnt);
    }

    for(int i=val; i > 1; i--) {
        if(make[i]) {
            if(val % i == 0) {
                solve(val / i, cnt + make[i] + 1);
            }
        }
    }
}

void making(int num, int cnt){
    if(cnt > 7) return;
    if(num > input) return;

    if(cnt > 0) {
        make[num] = cnt;
    }
    for(int i=0; i<10; i++) {
        if(cal[i]) making(num*10 + i, cnt + 1);
    }
    return ;
}
int main() {
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        answer = 987654321;
        memset(cal, 0, sizeof(cal));
        memset(make, 0, sizeof(make));
        for(int i=0; i<10; i++) {
            cin >> cal[i];
        }
        cin >> input;
        if(input == 1 && cal[1]) {
            answer = 2;
        } else {
            making(0, 0);
            if(make[input]) answer = make[input] + 1;
            else {
                solve(input, 0);
            }
        }
        printf("#%d %d\n", tc, answer==987654321?-1:answer);
    }
    return 0;
}