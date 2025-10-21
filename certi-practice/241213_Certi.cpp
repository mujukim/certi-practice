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