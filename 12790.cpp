#include <iostream>
using namespace std;
int T, hp, mp, str, def, a, b, c, d;
int main(){
    cin >> T;
    while(T--){
        cin >> hp >> mp >> str >> def;
        cin >> a >> b >> c >> d;
        hp += a;
        mp += b;
        str += c;
        def += d;
        if(hp < 1) hp = 1;
        if(mp < 1) mp = 1;
        if(str < 0) str = 0;
        cout << (hp) + 5*(mp) + 2*(str) + 2*(def) << "\n";
    }
    return 0;
}