// certi-practice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
int n = 0, accidentN = 0;
int CarX[2] = { 1,1 }, CarY[2] = { 1,1 };
int AccdentX[1000] = { 0, }, AccdentY[1000] = { 0, };
int totaldist = 0;
int result[1000] = { 0, };


void init();
void distance();

int main()
{
	init();
	distance();
	printf("%d\n", totaldist);
	for (int i = 0; i < accidentN; i++)
	{
		printf("%d\n", result[i]);
	}
}

void init()
{
	scanf("%d %d", &n, &accidentN);
	CarX[1] = n;
	CarY[1] = n;
	for (int i = 0; i < accidentN; i++)
	{
		scanf("%d %d", &AccdentX[i], &AccdentY[i]);
	}
}

void distance()
{
	int car1dist = 0, car2dist = 0;
	for (int a = 0; a < accidentN; a++)
	{
		car1dist = abs(CarX[0] - AccdentX[a]) + abs(CarY[0] - AccdentY[a]);
		car2dist = abs(CarX[1] - AccdentX[a]) + abs(CarY[1] - AccdentY[a]);
		if (car1dist > car2dist)
		{
			CarX[1] = AccdentX[a];
			CarY[1] = AccdentY[a];
			totaldist += car2dist;
			result[a] = 2;
		}
		else
		{
			CarX[0] = AccdentX[a];
			CarY[0] = AccdentY[a];
			totaldist += car1dist;
			result[a] = 1;
		}
	}
}



