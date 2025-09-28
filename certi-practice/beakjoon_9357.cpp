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
		long long ret = 1; // ����Ǽ��� ������ ���� Ŀ���� �ֱ� ������ long long�� �Ѵ�.
		for (auto c : clothes) {
			ret *= ((long long)c.second + 1); // ���Դ� ��� �����ϱ� ���� + 1
		}
		ret--; // �ƹ��͵� ���Դ� ��� ����
		cout << ret;
	}
}