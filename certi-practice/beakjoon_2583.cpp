//// 영역구하기
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#define MAX_ 102
//using namespace std;
//
//vector<int> ret;
//int M = 0, N = 0, K = 0;
//int map[MAX_][MAX_], visited[MAX_][MAX_];
//int sx;
//int sy;
//int ex;
//int ey;
//const int dx[4] = { -1, 0, 1, 0 };
//const int dy[4] = { 0, -1, 0, 1 };
//
//int dfs(int y, int x)
//{
//    visited[y][x] = 1;
//    int ret = 1;
//    for (int i = 0; i < 4; i++)
//    {
//        int ny = y + dy[i];
//        int nx = x + dx[i];
//        if (ny < 0 || ny >= M || nx < 0 || nx >= N || visited[ny][nx] == 1) continue;
//        if (map[ny][nx] == 1) continue;
//        ret += dfs(ny, nx);
//    }
//    return ret;
//}
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    memset(map, -1, sizeof(map));
//    cin >> M >> N >> K;
//    for (int i = 0; i < K; i++)
//    {
//        cin >> sx >> sy >> ex >> ey;
//        for (int x = sx; x < ex; x++)
//        {
//            for (int y = sy; y < ey; y++)
//            {
//                map[y][x] = 1;
//            }
//        }
//    }
//    for (int i = 0; i < M; i++)
//    {
//        for (int j = 0; j < N; j++)
//        {
//            if ((map[i][j] != 1) && (visited[i][j] == 0)) {
//                ret.push_back(dfs(i, j));
//            }
//        }
//    }
//    sort(ret.begin(), ret.end());
//    cout << ret.size() << "\n";
//    for (int a : ret) cout << a << " ";
//}