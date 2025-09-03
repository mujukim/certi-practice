// ���ǿ� ��ȸ

// ������ �������(a->b->c->d->a �̰Ŷ� b->c->d->a->b ���� ��¥�� ��ȸ�ϱ�)
// �����κб���(a->b������ �ּڰ�, a->b->c ������ �ּڰ�)
// => DP

// 31���� ���ϸ� ��Ʈ����ŷ�� ���� �ִ�.

#include <iostream>
#include <vector>
#include <cstring>
#define INF int(1e9);;
using namespace std;
int NumCity;
int W[16][16];
int dp[16][1<<16]; // [here][visited] : here���� �����ؼ� ������ �湮������ �ּڰ�

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
	if (visited == (1 << NumCity) - 1) // (1 << NumCity) -1 : N�� ���� ��� �湮
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
