// ³ó±¸°æ±â

#include <iostream>
#include <cstring>
using namespace std;


int num;
string player;
int a[26];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(a, 0x00, sizeof(a));
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> player;
		a[player[0] - 'a'] += 1;
	}
	string ret;
	for (int i = 0; i < 26; i++)
	{
		if (a[i] >= 5)
		{
			ret += i + 'a';
		}
	}
	if (ret == "")
		cout << "PREDAJA";
	else
		cout << ret;


	return 0;
}