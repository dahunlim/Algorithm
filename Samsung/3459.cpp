#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        unsigned long long N;
        cin >> N;
        int check = 0;
        unsigned long long base = 1;
        unsigned long long mul = 1;
        while (base < N){
            if(!check) mul *= 4;
            base += mul;
            check = !check;
        }
        cout << "#" << tc << " " << (check?"Alice":"Bob") << endl;
    }

    return 0;
}