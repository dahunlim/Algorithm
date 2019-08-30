// 1218. [S/W 문제해결 기본] 4일차 - 괄호 짝짓기
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <stack>
using namespace std;
int T;
string S;
int main() {
    for(int tc=1; tc <= 10; tc++) {
        stack<char> s1;
        cin >> T;
        cin >> S;
        int check = 1;
        for(int i=0; i<S.length(); i++) {
            char buf = S[i];
            if(buf == '(' || buf == '{' || buf == '<' || buf == '[') {
                s1.push(buf);
            } else {
                char front = s1.top();
                s1.pop();
                if(front == '(') {
                    if(buf != ')') {
                        check = 0;
                        break; 
                    }
                }
                if(front == '{') {
                    if(buf != '}') {
                        check = 0;
                        break;
                    }
                }
                if(front == '[') {
                    if(buf != ']') {
                        check = 0;
                        break; 
                    }
                }
                if(front == '<') {
                    if(buf != '>') {
                        check = 0;
                        break;
                    }
                }
            } 
        }
        cout << "#" << tc << " " << check << endl;
    }
    return 0;
}