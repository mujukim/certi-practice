#include <iostream>
#include <vector>
using namespace std;
int n, m;
int arr[15001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	int temp = 0;
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] + arr[j] == m)
				result++;
		}
	}
	cout << result << "\n";

}