#include <iostream>
#include <map>
using namespace std;
int n, tc;
map<string, int> clothes;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> tc >> n;
	string temp, temp2;
	for (int i = 0; i < tc; i++)
	{
		clothes.clear();
		for (int j = 0; j < n; j++)
		{
			cin >> temp >> temp2;
			clothes[temp2]++;
		}
		long long ret = 1; // 경우의수면 무조건 수가 커질수 있기 때문에 long long을 한다.
		for (auto c : clothes) {
			ret *= ((long long)c.second + 1); // 안입는 경우 포함하기 위해 + 1
		}
		ret--; // 아무것도 안입는 경우 삭제
		cout << ret;
	}
}