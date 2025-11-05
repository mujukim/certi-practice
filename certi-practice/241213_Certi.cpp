// 상품을 랭킹순으로 정렬
// id를 기준으로 상품을 제거
// id를 기준으로 상품의 랭킹을 변경
// 카테코리 내 두 랭크 상품 전체 교체

// ## 자료구조
// unordered_map<int, pair<int, int>> GoodsInfo;  
// key : ID, value : (category, rank)

// set<int> RankSet[category 개수][랭킹 개수] = 들어있는건 ID 집합(오름차순 정렬됨)
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
	total.insert(make_pair(mRank, -mGoodsID)); // rank 순으로 배열하기 위해서 -mGoodsID를 함

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