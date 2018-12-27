#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main(void)
{

    char map[51][51];
    int ax[4] = {1, -1, 0, 0};
    int ay[4] = {0, 0, 1, -1};
    int max = 0;
    int a, b;
    char input;
    queue<pair<int, int>> q1;

    cin >> a >> b;

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cin >> input;
            map[i][j] = input;
        }
    }

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (map[i][j] == 'L')
            {
                int check[51][51] = {0};
                q1.push(make_pair(i, j));
                check[i][j] = 1;

                while (!q1.empty())
                {
                    int nx = q1.front().first;
                    int ny = q1.front().second;

                    q1.pop();
                    if (check[nx][ny] > max)
                    {
                        max = check[nx][ny];
                    }

                    for (int k = 0; k < 4; k++)
                    {
                        int dfsx = nx + ax[k];
                        int dfsy = ny + ay[k];

                        if (0 <= dfsx && dfsx < a && 0 <= dfsy && dfsy < b && map[dfsx][dfsy] == 'L' && check[dfsx][dfsy] == 0)
                        {
                            check[dfsx][dfsy] = check[nx][ny] + 1;
                            q1.push(make_pair(dfsx, dfsy));
                        }
                    }
                }
            }
        }
    }

    cout << max - 1;
    return 0;
}