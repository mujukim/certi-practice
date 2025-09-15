//9996 한국이 그리울 땐 서버에 접속하지
// substr

#include <iostream>

using namespace std;
int num;
string pattern, prefix, suffix;
string input[102]; // 원래 값보다 조금 넉넉하게 두자 
bool check(string file)
{
	if (file.size() < prefix.size() + suffix.size()) return false;
	string a = file.substr(0, prefix.size());
	string b = file.substr(file.size() - suffix.size());
	if ((prefix == a) && (suffix == b))
		return true;
	else
		return false;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> num;
	cin >> pattern;
	int pos = pattern.find('*');
	prefix = pattern.substr(0, pos); // 0~pos 전까지 분리
	suffix = pattern.substr(pos + 1); // pos + 1 부터 끝까지 분리
	for (int i = 0; i < num; i++)
	{
		cin >> input[i];
		if (check(input[i]))
			cout << "DA\n";
		else
			cout << "NE\n";
	}
	return 0;

}