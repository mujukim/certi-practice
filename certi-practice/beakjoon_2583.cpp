// 영역구하기

#include<iostream>
#define MAX_ 100
using namespace std;

int M = 0, N = 0, K = 0;
int map[MAX_][MAX_];
int sx[MAX_];
int sy[MAX_];
int ex[MAX_];
int ey[MAX_];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(map, -1, sizeof(map));
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> sx[i] >> sy[i] >> ex[i] >> ey[i];
    }

    // map에 rect 채우기
    for (int m = 0; m < M; m++)
    {
        for (int n = 0; n < N; n++)
        {
            for (int k = 0; k < K; k++)
            {           
                if ((map[m][n] >= sx[k] && map[m][n] < ex[k]) &&
                    (map[m][n] >= sy[k] && map[m][n] < ey[k]))
                {
                    map[m][n] = 1;
                }
                else
                {
                    map[m][n] = 0;
                }
            }
        }
    }
  
    // 영역찾아내기
}