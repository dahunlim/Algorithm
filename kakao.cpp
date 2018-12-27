#include <vector>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int main() {
    int m;
    int n;
    vector<vector<int>> picture;
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int check[100][100] = {};
    int ax[4] = {0, 0, 1, -1};
    int ay[4] = {1, -1, 0, 0};
    int color = 0;
    int size = 0;
    cin >> m >> n;
    for(int i=0; i<m; i++) for(int j=0; j<n; j++) cin >> picture[i][j];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(check[i][j]) continue;
            if(picture[i][j] == 0) continue;
            queue<pair<int ,int>> q;
            q.push(make_pair(i,j));
            color = picture[i][j];
            size = 1;
            number_of_area++;
            while(!q.empty()){
                int oldx = q.front().first;
                int oldy = q.front().second;
                q.pop();
                for(int i=0; i<4; i++){
                    int newx = oldx + ax[i];
                    int newy = oldy + ay[i];
                    if(newx < 0 || newx >= m || newy < 0 || newy >= n || picture[newx][newy] != color) continue;
                    q.push(make_pair(newx, newy));
                    check[newx][newy] = 1;
                    size++;
                    if(max_size_of_one_area < size) max_size_of_one_area = size;
                }
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    cout << answer[0] << answer[1];
    return 0;
}