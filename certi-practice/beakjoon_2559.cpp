//#include <iostream>
//
//using namespace std;
//
//int N, K, psum[100001];
//
//int calc()
//{
//	int ret = -1e9;
//	for (int i = K; i <= N; i++)
//	{
//		ret = max(ret, psum[i] - psum[i - K]);
//	}
//	return ret;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> N >> K;
//	int input;
//	psum[0] = 0;
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> input;
//		psum[i] = psum[i - 1] + input;
//	}
//	cout << calc();
//	return 0;
//}