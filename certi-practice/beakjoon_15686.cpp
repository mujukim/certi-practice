//// 치킨 배달
//#include <iostream>
//#include <vector>
//using namespace std;
//int N, M, Map[51][51];
//vector<pair<int, int>> home, chicken;
//vector<vector<int>> chickenList;
//void init()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> N;
//	cin >> M;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			cin >> Map[i][j];
//			if (Map[i][j] == 1) home.push_back({ i, j });
//			if (Map[i][j] == 2) chicken.push_back({ i, j });
//		}
//	}
//}
//
//void combi(int start, vector<int> v) // 치킨 가게 m 수만큼 나올 조합
//{
//	if (v.size() == M)
//	{
//		chickenList.push_back(v);
//	}
//	for (int i = start + 1; i < chicken.size(); i++)
//	{
//		v.push_back(i);
//		combi(i, v);
//		v.pop_back();
//	}
//}
//
//int main()
//{
//	init();
//	vector<int> v;
//	int result = 1e9;
//	combi(-1, v);
//	for (vector<int> cList : chickenList) {
//		int ret = 0;
//		for (pair<int, int> home : home) {
//			int _min = 1e9;
//			for (int ch : cList) {
//				int _dist = abs(home.first - chicken[ch].first) + abs(home.second - chicken[ch].second);
//				_min = min(_min, _dist);
//			}
//			ret += _min;
//		}
//		result = min(result, ret);
//	}
//	cout << result << "\n";
//	return 0;
//}