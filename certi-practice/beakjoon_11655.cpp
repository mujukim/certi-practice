// 11655번 ROT13
// A = 65, a = 97 ==> 이건 외우자 


#include <iostream>
#include <string>
using namespace std;


string ROT13(string input)
{
	string ret;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] >= 65 && input[i] <= 90) // 대문자
		{
			if (input[i] + 13 > 90)
				input[i] = input[i] + 13 - 26;
			else
				input[i] = input[i] + 13;
		}
		else if (input[i] >= 97 && input[i] <= 122) // 소문자
		{
			if (input[i] + 13 > 122)
				input[i] = input[i] + 13 - 26;
			else
				input[i] = input[i] + 13;
		}
	}
	return input;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string input;
	//cin >> input;
	getline(cin, input); // 띄어쓰기가 있는 문자열을 받을때 쓴다. 

	string output = ROT13(input);
	cout << output;
}