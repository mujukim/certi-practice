#include <iostream>

using namespace std;

int N, K, numarr[100001];

int calc()
{
	int i = 0, max = -1e9, val = 0;
	while (true)
	{
		if (N - 1 < i + K) break;
		for (int j = 0; j < K; j++)
		{
			val += numarr[i + j];
		}
		if (max < val)
			max = val;
		i++;
		val = 0;
	}
	return max;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> numarr[i];
	}
	cout << calc();
	return 0;
}