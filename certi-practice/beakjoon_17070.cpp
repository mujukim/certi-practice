// 파이프 옮기기 1 
#include <cstring>
#include <iostream>

using namespace std;

int map[16 + 1][16 + 1];
int HouseSize;
int dp[16 + 1][16 + 1][3]; // x, y, 방향(0 = 가로, 1 = 대각선, 2 = 세로)

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(map, 0, sizeof(map));
	memset(dp, 0, sizeof(dp));

	cin >> HouseSize;
	for (int i = 0; i < HouseSize; i++)
	{
		for (int j = 0; j < HouseSize; j++)
		{
			cin >> map[i][j];
		}
	}
}
bool check(int x, int y, int dir)
{
	switch (dir)
	{
	case 0:
	case 2:
		if ((map[x][y] == 0))
			return true;
		break;
	case 1:
		if ((map[x - 1][y] == 0) && (map[x][y - 1] == 0) && (map[x][y] == 0))
			return true;
		break;
	default:
		return false;
		break;
	}
	return false;
}
int calculate()
{
	dp[2][1][0] = 1;
	for (int i = 1; i <= HouseSize; i++)
	{
		for (int j = 1; j <= HouseSize; j++)
		{
			// 가로일 경우
			if (check(i + 1, j, 0)) dp[i + 1][j][0] += dp[i][j][0];
			if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][0];
			// 세로일 경우
			if (check(i, j + 1, 2)) dp[i][j + 1][2] += dp[i][j][2];
			if (check(i + 1, j + 1, 2)) dp[i + 1][j + 1][1] += dp[i][j][2];
			// 대각선일 경우
			if (check(i + 1, j, 1)) dp[i + 1][j][0] += dp[i][j][1];
			if (check(i + 1, j, 1)) dp[i][j + 1][2] += dp[i][j][1];
			if (check(i + 1, j, 1)) dp[i + 1][i + 1][1] += dp[i][j][1];
		}
	}
	return dp[HouseSize][HouseSize][0] + dp[HouseSize][HouseSize][1] + dp[HouseSize][HouseSize][2];
}

int main()
{
	init();
	cout << calculate();
}