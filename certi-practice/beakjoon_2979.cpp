#include<iostream>
#include<cstring>
using namespace std;

int a, b, c;
int timearr[101];
int max_time;
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a;
	cin >> b;
	cin >> c;
	memset(timearr, 0x00, sizeof(timearr));
	int start_, end_;
	max_time = 0;
	for (int i = 0; i < 3; i++)
	{
		cin >> start_ >> end_;
		if (max_time < end_) max_time = end_;
		for (int j = start_; j < end_; j++)
		{
			timearr[j]++;
		}
	}
}

int solve()
{
	int ret = 0;
	for (int i = 1; i <= max_time; i++)
	{	
		if (timearr[i] == 1) ret += a;
		else if (timearr[i] == 2) ret += (b * 2);
		else if (timearr[i] == 3) ret += (c * 3);
	}
	return ret;
}

int main()
{
	init();
	cout << solve();
}