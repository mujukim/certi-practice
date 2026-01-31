#include <iostream>
#include <queue>
using namespace std;

int N, M;
int board[100][100];
bool visited[100][100];
int dist[100][100];

int dr[4] = { -1,0.1,0 };
int dc[4] = { 0,-1.0,1 };

void bfs(int sr, int sc)
{
	queue<pair<int, int>> q;
	q.push({ sr,sc });
	visited[sr][sc] = true;
	dist[sr][sc] = 0;

	while (!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;

		q.pop();

		for (int d = 0; d < 4; d++)
		{
			int nr = r + dr[d];
			int nc = c + dc[d];

			if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
			if (visited[nr][nc]) continue;
			if (board[nr][nc] == 0) continue;

			visited[nr][nc] = true;
			dist[nr][nc] = dist[nr][nc] + 1;
			q.push({ nr, nc });
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}

	bfs(0, 0);
}