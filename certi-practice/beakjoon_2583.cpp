// 영역구하기

#include<iostream>
#define MAX_ 102
using namespace std;

int M = 0, N = 0, K = 0;
int map[MAX_][MAX_], visited[MAX_][MAX_];
int sx;
int sy;
int ex;
int ey;
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };
int dfs(int y, int x)
{
    visited[y][x] = 1;
    int ret = 1;
    for (int i = 0; i < 4; i++)
    {

    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(map, -1, sizeof(map));
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> sx >> sy >> ex >> ey;
        for (int x = sx; x < ex; x++)
        {
            for (int y = sy; y < ey; y++)
            {
                map[y][x] = 1;
            }
        }
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {

        }
    }
  
    // 영역찾아내기
}