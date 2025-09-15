//9996 �ѱ��� �׸��� �� ������ ��������
// substr

#include <iostream>

using namespace std;
int num;
string pattern, prefix, suffix;
string input[102]; // ���� ������ ���� �˳��ϰ� ���� 
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
	prefix = pattern.substr(0, pos); // 0~pos ������ �и�
	suffix = pattern.substr(pos + 1); // pos + 1 ���� ������ �и�
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