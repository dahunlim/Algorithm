#include <iostream>
#include <string>
#include <queue>
#include <cstdlib>
using namespace std;
string year[25] = {"1967", "1969", "1970", "1971", "1972", "1973", "1973", "1974", "1975", "1976",
                  "1977", "1977", "1979", "1980", "1983", "1984", "1987", "1993", "1995", "1997",
                  "1999", "2002", "2003", "2013", "2016"};
string name[25] = {"DavidBowie", "SpaceOddity", "TheManWhoSoldTheWorld", "HunkyDory", "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars",
                  "AladdinSane", "PinUps", "DiamondDogs", "YoungAmericans", "StationToStation", "Low", "Heroes", "Lodger",
                  "ScaryMonstersAndSuperCreeps", "LetsDance", "Tonight", "NeverLetMeDown", "BlackTieWhiteNoise",
                  "1.Outside", "Earthling", "Hours", "Heathen", "Reality", "TheNextDay", "BlackStar"};
int Q, st, la;
queue<int> q;
int main()
{
    cin >> Q;
    while(Q--){
        int count = 0;
        cin >> st >> la;
        for(int i=0; i<25; i++){
            if(atoi(year[i].c_str()) >= st && atoi(year[i].c_str()) <= la){
                count++;
                q.push(i);
            }
        }
        cout << count << "\n";
        while(!q.empty()){
            cout << year[q.front()] << " "<< name[q.front()] << "\n";
            q.pop();
        }
    }
    return 0;
}
