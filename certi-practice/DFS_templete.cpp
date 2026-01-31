#include <iostream>
using namespace std;

int N, M;
int board[100][100];
bool visited[100][100];

// »óÇÏÁÂ¿ì
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, - 1, 1};

void dfs(int r, int c)
{
	visited[r][c] = true;

	for (int d = 0; d < 4; d++)
	{
		int nr = r + dr[d];
		int nc = c + dc[d];

		if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
		if (visited[nr][nc])continue;
		if (board[nr][nc] == 0) continue; // ¸ø°¡´Â Ä­

		dfs(nr, nc);
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; i < M; i++)
		{
			dfs(i, j);
		}
	}
}