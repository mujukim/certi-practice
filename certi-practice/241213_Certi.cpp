// ��ǰ�� ��ŷ������ ����
// id�� �������� ��ǰ�� ����
// id�� �������� ��ǰ�� ��ŷ�� ����
// ī���ڸ� �� �� ��ũ ��ǰ ��ü ��ü

// ## �ڷᱸ��
// unordered_map<int, pair<int, int>> GoodsInfo;  
// key : ID, value : (category, rank)

// set<int> RankSet[category ����][��ŷ ����] = ����ִ°� ID ����(�������� ���ĵ�)
// RankSet[1][2].insert(10);
// RankSet[1][2].insert(20);
// RankSet[1][1].insert(30);
//   -> category 1, rank 2 = {20, 10}
//   -> category 1, rank 1 = {30}


#include <iostream>
using namespace std;

struct ResultST
{
	int mID[3];
};

void init()
{

}

int add(int mGoodsID, int mCategory, int mRank)
{

}

int remove(int mGoodsID)
{

}

int changeRank(int mGoodsID, int mRank)
{

}

int swapRank(int category, int mRank1, int mRank2)
{

}

ResultST GetTopRanks()
{

}