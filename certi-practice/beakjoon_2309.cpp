//// �ϰ�������
//
//// �������� Ǯ��
//// 9�� �� 7�� �̾Ƽ� �� ���ؼ� 100�� �� �� �� ���� ����ϱ� 
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//int height[9];
//int a, b;
//void init()
//{
//	//�ð�����
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	for (int i = 0; i < 9; i++)
//	{
//		cin >> height[i];
//	}
//}
//void combi()
//{
//	for (a = 0; a < 9; a++)
//	{
//		for (b = a + 1; b < 9; b++)
//		{
//			if (a == b) continue;
//
//			int sum = 0;
//			for (int k = 0; k < 9; k++)
//			{
//				if ((k == a) || (k == b)) continue;
//				sum += height[k];
//			}
//			if (sum == 100) return;
//		}
//	}
//}
//int main()
//{
//	init();
//	sort(height, height + 9);
//	combi();
//	for (int i = 0; i < 9; i++)
//	{
//		if ((i == a) || (i == b)) continue;
//		cout << height[i] << "\n";
//	}
//	return 0;
//}