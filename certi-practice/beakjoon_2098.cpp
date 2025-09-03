// 외판원 순회

// 순서와 상관없음(a->b->c->d->a 이거랑 b->c->d->a->b 같음 어짜피 순회니까)
// 최적부분구조(a->b까지의 최솟값, a->b->c 까지의 최솟값)
// => DP

// 31가지 이하면 비트마스킹을 쓸수 있다.

#include <iostream>
#include <vector>
#include <cstring>
#define INF int(1e9);;
using namespace std;
int NumCity;
int W[16][16];
int dp[16][1<<16]; // [here][visited] : here에서 시작해서 어디까지 방문했을때 최솟값

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(W, 0, sizeof(int) * 16 * 16);
	memset(dp, -1, sizeof(dp));

	cin >> NumCity;
	for (int i = 0; i < NumCity; i++)
	{
		for (int j = 0; j < NumCity; j++)
		{
			cin >> W[i][j];
		}
	}
}

int solution(int here, int visited)
{
	if (visited == (1 << NumCity) - 1) // (1 << NumCity) -1 : N개 도시 모두 방문
	{
		return W[here][0] ? W[here][0] : INF;
	}
	int& ret = dp[here][visited];
	if (ret != -1) return ret;
	ret = INF;
	for (int i = 0; i < NumCity; i++)
	{
		if (visited & (1 << i)) continue;
		if (W[here][i] == 0) continue;
		ret = min(ret, solution(i, (visited | (1 << i))) + W[here][i]);
	}
 	return ret;
}

int main()
{
	init();
	cout << solution(0, 1);
	return 0;
}
