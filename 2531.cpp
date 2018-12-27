#include <iostream>
using namespace std;
int N, d, k, c, temp, result;
int list[33002];
int main(){
    cin >> N >> d >> k >> c;
    for(int i=0; i<N; i++){
        cin >> list[i];
    }
    for(int i=0; i<k; i++) list[N+i] = list[i];
    for(int i=0; i<N; i++){
        int count[3001] = {};
        temp = 0;
        for(int j=0; j<k; j++){
            if(count[list[i+j]] == 0){
                count[list[i+j]]++;
                temp++;
            }
            else{
                count[list[i+j]]++;
            }
        }
        if(count[c] == 0 ) temp++;
        if(result < temp) result = temp;        
    }
    cout << result;
    return 0;
}