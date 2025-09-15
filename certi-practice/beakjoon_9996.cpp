#include <iostream>

using namespace std;
int num;
string pattern;
string input[100];
bool check(string file)
{
	bool ret = true;
	for (int i = 0; i < file.size(); i++)
	{
		if (pattern[i] == 42) break;
		if (file[i] != pattern[i])
		{
			ret = false;
			break;
		}
	}

	if (!ret) return ret;

	for (int i = 1; i < file.size(); i++)
	{
		if (pattern[pattern.size() - i] == 42) break;
		if (file[file.size() - i] != pattern[pattern.size() - i])
		{
			ret = false;
			break;
		}
	}
	return ret;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> num;
	cin >> pattern;
	for (int i = 0; i < num; i++)
	{
		cin >> input[i];
	}
	for (int i = 0; i < num; i++)
	{
		if (check(input[i]))
			cout << "DA\n";
		else
			cout << "NE\n";
	}
}