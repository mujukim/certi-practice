// certi-practice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
int n = 0, accidentN = 0;
int CarX[2] = { 1,1 }, CarY[2] = { 1,1 };
int PointX[1002] = { 0, }, PointY[1002] = { 0, };
int totaldist = 0;
int result[1001] = { 0, };
int dp[1001][1001];

void init();
int distance(int car1, int car2);
void solve();
int main()
{
	init();
	printf("%d\n", distance(0, 1));
	solve();
}

void init()
{
	memset(dp, -1, sizeof(int) * 1001 * 1001);
	scanf("%d %d", &n, &accidentN);
	PointX[0] = 1;
	PointY[0] = 1;
	PointX[1] = n;
	PointY[1] = n;
	for (int i = 2; i < accidentN + 2; i++)
	{
		scanf("%d %d", &PointX[i], &PointY[i]);
	}
}

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
int calc_dist(int car1, int car2)
{
	return abs(PointX[car1] - PointX[car2]) + abs(PointY[car1] - PointY[car2]);
}
int distance(int car1, int car2)
{
	if (car1 == accidentN + 1 || car2 == accidentN + 1) return 0;
	if (dp[car1][car2] != -1) return dp[car1][car2];
	
	int next = max(car1,car2) + 1;
	
	return dp[car1][car2] = min(distance(car1, next) + calc_dist(next, car2), distance(next, car2) + calc_dist(next, car1));

}
void solve()
{
	int car1 = 0, car2 = 1;
	for (int i = 2; i < accidentN + 2; i++)
	{
		if (dp[i][car2] + calc_dist(i, car1) > dp[car1][i] + calc_dist(i, car2))
		{
			printf("2\n");
			car2 = i;
		}
		else
		{
			printf("1\n");
			car1 = i;
		}
			
	}
}


// https://lionkingchuchu.tistory.com/21 이거 참고하도록... .
