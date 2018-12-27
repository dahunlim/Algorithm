#include <iostream>
using namespace std;
int s1, s2, a1, a2;
int main(){
    cin >> s1 >> s2;
    for(int i=0; i<s1; i++){
        cin >> a1 >> a2;
        if(a1 != a2){
            cout << "Wrong Answer";
            return 0;
        }  
    }
    for(int i=0; i<s2; i++){
        cin >> a1 >> a2;
        if(a1 != a2){
            cout << "Why Wrong!!!";
            return 0;
        }
    }
    cout << "Accepted";
    return 0;
}