//#include <iostream>
//#include <queue>
//using namespace std;
//int n, m;
//const int max_n = 102;
//int map[max_n][max_n];
//int visited[max_n][max_n];
//int x, y;
//int dy[4] = { -1, 0, 1, 0 };
//int dx[4] = { 0, 1, 0, -1 };
//
//void init()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//}
//
//int main()
//{
//	init();
//	cin >> n >> m;
//    string line;
//	for (int i = 0; i < n; i++)
//	{
//        cin >> line;
//		for (int j = 0; j < m; j++)
//		{
//            map[i][j] = line[j] - '0';
//		}
//	}
//
//    queue<pair<int, int>> q;
//    visited[0][0] = 1;
//    q.push({ 0, 0 });
//    while (q.size()) {
//        y = q.front().first;
//        x = q.front().second;
//        q.pop();
//        for (int i = 0; i < 4; i++) {
//            int ny = y + dy[i];
//            int nx = x + dx[i];
//            if (ny < 0 || ny >= n || nx < 0 || nx >= m || map[ny][nx] == 0) continue;
//            if (visited[ny][nx]) continue;
//            visited[ny][nx] = visited[y][x] + 1;
//            q.push({ ny, nx });
//        }
//    }
//    cout << visited[n - 1][m - 1];
//    return 1;
//}