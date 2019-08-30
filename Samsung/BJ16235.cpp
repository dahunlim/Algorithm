// 16235 나무 재테크
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, K, x, y, z;
int energy[11][11];
int energy_add[11][11];
vector<int> map[11][11];
int ax[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int ay[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
void spring() {
    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) {
        vector<int> temp;
        int die_tree = 0;
        sort(map[i][j].begin(), map[i][j].end());
        for(int k=0; k<map[i][j].size(); k++) {
            int age = map[i][j].at(k);
            // cout << "#" << age << " " << energy[i][j] << endl;
            if(age <= energy[i][j]) {
                // cout << i << " " << j << " " << age << " " << energy[i][j] << " " << map[i][j].size() << endl;
                energy[i][j] = energy[i][j] - age;
                temp.push_back(age + 1);
            } else {
                die_tree += (age / 2);
            }  
        }
        
        map[i][j].clear();
        for(int k=0; k<temp.size(); k++) {
            map[i][j].push_back(temp.at(k));
        }
        energy[i][j] += die_tree;
    }
}

void fall() {
    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) {
        for(int k=0; k<map[i][j].size(); k++) {
            int tree = map[i][j].at(k);

            if(tree % 5 == 0) {
                for(int h=0; h<8; h++) {
                    int nx = i + ax[h];
                    int ny = j + ay[h];

                    if(nx < 1 || nx > N || ny < 1 || ny > N) continue;
                    else {
                        map[nx][ny].push_back(1);
                    }
                }
            }
        }
    }
}

void winter() {
    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) {
        energy[i][j] += energy_add[i][j];
    }
}
int main() {
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) {
        cin >> energy_add[i][j];
        energy[i][j] = 5;
    }
    for(int i=0; i<M; i++) {
        cin >> x >> y >> z;
        map[x][y].push_back(z);
    }

    for(int i=0; i<K; i++) {
        spring();
        fall();
        winter();
    }
    int result = 0;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            // printf("%2d ", energy[i][j]);
            // if(map[i][j].size()) cout << i << " " << j << " " << map[i][j].size() << endl;
            // printf("%d ", map[i][j].size());
            result += map[i][j].size();
        }
        // cout << endl;
    }

    cout << result;
    return 0;
}