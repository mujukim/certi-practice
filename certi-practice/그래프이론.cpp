#include <iostream>
#include <vector>
using namespace std;

// 그래프 표현에는 인접행렬, 인접리스트가 있다
// 인접행렬 (대칭임)
bool a[4][4] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 0},
    {1, 0, 0, 0},
};
//1번.
//정점은 0번 부터 9번까지 10개의 노드가 있다. 1 - 2 / 1 - 3 / 3 - 4 라는 경로가 있다. (1번과 2번, 1번과 3번, 3번과 4번은 연결되어있다.)
//이를 인접행렬로 표현한다면 ?
//0번부터 방문안한 노드를 찾고 해당 노드부터 방문, 연결된 노드를 이어서 방문해서 출력하는 재귀함수를 만들고 싶다면 어떻게 해야할까 ? 또한, 정점을 방문하고 다시 방문하지 않게 만드려면 어떻게 해야할까 ?

//답
const int V = 10;
bool a[V][V], visited[V];
void go(int from)
{
    visited[from] = 1;
    cout << from << "/n"; // 방문했음을 출력
    for (int i = 0; i < V; i++)
    {
        if (visited[i]) continue;
        if (a[from][i])
        {
            go(i); // a에 값이 존재해야 방문
        }
    }
}
int main() {
    a[1][2] = 1; a[1][3] = 1; a[3][4] = 1;
    a[2][1] = 1; a[3][1] = 1; a[4][3] = 1;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (a[i][j] && visited[i] == 0) {
                go(i);
            }
        }
    }
}


//인접리스트
//간선들을 배열에 넣은 것
// 0 : 1,2,3 과 연결
// 1 : 0,2 연결
// 2 : 0,1 연결
// 3 : 0 과 연결
const int V = 4;
vector<int> adj[V];
void init()
{
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);

    adj[1].push_back(0);
    adj[1].push_back(2);

    adj[2].push_back(0);
    adj[2].push_back(1);

    adj[3].push_back(0);
}