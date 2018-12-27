#include <iostream>
using namespace std;
int N, input;
int main(){
     cin >> N;
    for(int i=1; i<=N; i++){
        cin >> input;
        if(input == i){
            cout << "-1";
            return 0;
        }
    }
    cout << "1000003";
    return 0;
}