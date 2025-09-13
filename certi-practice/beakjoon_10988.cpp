#include<iostream>

using namespace std;

int main()
{
	string input;
	cin >> input;
	int strsize = input.size();
	int ret = 1;
	for (int i = 0; i < strsize / 2; i++)
	{
		if (input[i] != input[strsize - 1 - i])
		{
			ret = 0;
			break;
		}
	}
	cout << ret;
}