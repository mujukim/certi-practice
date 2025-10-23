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
#include <unordered_map>
#include <set>
using namespace std;

struct ResultST
{
	int mID[3];
};
unordered_map<int, pair<int, int>> goodsInfo;
set<int> catRankSet[6][6];
set<pair<int, int>> total;

void init()
{
	goodsInfo.clear();
	total.clear();
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			catRankSet[i][j].clear();
		}
	}
}

int add(int mGoodsID, int mCategory, int mRank)
{
	goodsInfo[mGoodsID] = make_pair(mCategory, mRank);
	catRankSet[mCategory][mRank].insert(mGoodsID);
	total.insert(make_pair(mRank, -mGoodsID)); // rank ������ �迭�ϱ� ���ؼ� -mGoodsID�� ��
	int cnt = 0;
	for (int r = 1; r <= 5; r++) {
		cnt += (int)catRankSet[mCategory][r].size();
	}
	return cnt;
}

int remove(int mGoodsID)
{
	pair<int, int> info = goodsInfo[mGoodsID];
	int cat = info.first;
	int rank = info.second;

	goodsInfo.erase(mGoodsID);
	catRankSet[cat][rank].erase(mGoodsID);
	total.erase(make_pair(rank, -mGoodsID));

	int cnt = 0;
	for (int r = 1; r <= 5; r++) {
		cnt += (int)catRankSet[cat][r].size();
	}
	return cnt;
}

int changeRank(int mGoodsID, int mRank)
{
	pair<int, int> info = goodsInfo[mGoodsID];
	int cat = info.first;
	int oldRank = info.second;

	goodsInfo[mGoodsID].second = mRank;
	catRankSet[cat][oldRank].erase(mGoodsID);
	catRankSet[cat][mRank].insert(mGoodsID);
	total.erase(make_pair(oldRank, -mGoodsID));
	total.insert(make_pair(mRank, -mGoodsID));

	// �ش� ī�װ����� ���� ���� ��ŷ ID ã��
	for (int r = 1; r <= 5; r++) {
		if (!catRankSet[cat][r].empty()) {
			set<int>::iterator it = catRankSet[cat][r].end();
			it--; // rbegin() ��� ���� �̵�
			return *it;
		}
	}
	return -1;
}

int swapRank(int category, int mRank1, int mRank2)
{
	if (mRank1 == mRank2) return 0;

	int cnt1 = (int)catRankSet[category][mRank1].size();
	int cnt2 = (int)catRankSet[category][mRank2].size();

	// ���� set ����
	set<int> tmp1 = catRankSet[category][mRank1];
	set<int> tmp2 = catRankSet[category][mRank2];

	catRankSet[category][mRank1].clear();
	catRankSet[category][mRank2].clear();

	// rank1 �� rank2
	for (set<int>::iterator it = tmp1.begin(); it != tmp1.end(); ++it) {
		int id = *it;
		goodsInfo[id].second = mRank2;
		catRankSet[category][mRank2].insert(id);
		total.erase(make_pair(mRank1, -id));
		total.insert(make_pair(mRank2, -id));
	}

	// rank2 �� rank1
	for (set<int>::iterator it = tmp2.begin(); it != tmp2.end(); ++it) {
		int id = *it;
		goodsInfo[id].second = mRank1;
		catRankSet[category][mRank1].insert(id);
		total.erase(make_pair(mRank2, -id));
		total.insert(make_pair(mRank1, -id));
	}

	return cnt1 - cnt2;
}

ResultST GetTopRanks()
{
	ResultST res;
	int i = 0;

	for (set<pair<int, int>>::iterator it = total.begin(); it != total.end() && i < 3; ++it) {
		res.mID[i] = -((*it).second);
		i++;
	}

	while (i < 3) {
		res.mID[i] = -1;
		i++;
	}

	return res;
}