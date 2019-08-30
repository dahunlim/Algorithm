// BJ6603 로또
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <vector>
using namespace std;
int K;
vector<int> v1;
vector<int> result;
void select(int idx, int cnt){
    if(idx == K) {
        if(cnt == 6) {
            for(int i=0; i<result.size(); i++) cout << result.at(i) << " ";
            cout << endl;
        }
    } else {
        
        result.push_back(v1.at(idx));
        select(idx + 1, cnt + 1);
        result.pop_back();

        select(idx + 1, cnt);
    }
}
int main() {
    while(1) {
        result.clear();
        v1.clear();
        cin >> K;
        if(K == 0) {
            break;
        } else {
            for(int i=0; i<K; i++) {
                int input;
                cin >> input;
                v1.push_back(input);
            }
            select(0, 0);
            cout << endl;
        }
    }
    return 0;
}