#include <iostream>
#include <vector>
#include <queue>
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

//-> 보통은 인접리스트로 풀고 문제에 행렬로 나왔을때만 행렬로 풀자!

//좌표 탐색
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};
int main()
{
    int y = 0, x = 0;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int ny = x + dy[i];
    }
}

//Q. 3 * 3 맵을 입력받아야 함. 이 맵은 1과 0으로 이루어져있고 {0, 0}은 무조건 1임을 보장한다.
//{0, 0}부터 4방향을 기준으로 한칸씩 탐색해나가며 방문한 정점은 다시 방문하지 않으며 방문하는 좌표를 출력하는 코드.
//0은 갈 수 없는 지역. 1은 갈 수 있는 지역을 구현하시오.

const int n = 3;
int a[n][n];
int visited_[n][n] = { 0, };
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, -1, 0, 1 };
 
void go(int y, int x) {
    visited_[y][x] = 1;
    cout << y << " : " << x << "\n"; // 방문한 좌표 출력
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if (a[ny][nx] == 0) continue;
        if (visited_[ny][nx]) continue;
        go(ny, nx);
    }
    return;
}

//DFS
// 정점 u의 visited를 참으로 바꾸고 u와 연결된 v들을 방문한다 
//DFS(u, adj)
// u.visited = true
//  for each v ∈ adj[u]
//    if v.visited == false
//      DFS(v, adj)

// 컴포넌트 찾기 
// 컴포넌트 : 맵상에서 연결된 묶음들 라벨 붙이기 같은거. 
// Q. 종화는 방구쟁이야

int dx[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int m, n, k, y, x, ret, ny, nx, t;
int b[104][104];
bool b_visited[104][104];
void b_dfs(int y, int x)
{
    b_visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (b[ny][nx] == 1 && !b_visited[ny][nx]) {
            b_dfs(ny, nx);
        }
    }
    return;

}
int main() {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1 && !b_visited[i][j]) // 육지고 방문하지 않았다면 새로운 묶음 시작
            { 
                ret++; b_dfs(i, j); // 한 묶음 다 돌고나서 탈출함
            }
        }
    }
    cout << ret << '\n';
    return 0;
}

// BFS
// 같은 레이어에 있는 것들 먼저 돈다, 깊이우선탐색, 최단거리알고리즘
// 수도코드 1
// BFS(G, u)
//  u.visited = true
//  q.push(u)
//  while(q.size())
//    u = q.front()
//    q.pop()
//    for each v < G.adj[u]
//      if v.visited == false
//         v.visited = true
//         q.push(v)

// 근데 위에서 최단거리를 하려면 v.visited = true를 v.visited = u.visited + 1 로 변경
// 그러면 visited는 처음시작부터 해당 정점까지 오는데 걸린 시간이 나옴

vector<int> adj[100];
int visited[100];
int nodeList[] = { 10, 12, 14, 16, 18, 20, 22, 24 };
void bfs(int here) {
    queue<int> q;
    visited[here] = 1;
    q.push(here);
    while (q.size()) {
        int here = q.front(); q.pop();
        for (int there : adj[here]) {
            if (visited[there]) continue;
            visited[there] = visited[here] + 1;
            q.push(there);
        }
    }
}
int main() {
    adj[10].push_back(12);
    adj[10].push_back(14);
    adj[10].push_back(16);

    adj[12].push_back(18);
    adj[12].push_back(20);


    adj[20].push_back(22);
    adj[20].push_back(24);
    bfs(10);
    for (int i : nodeList) {
        cout << i << " : " << visited[i] << '\n';
    }
    cout << "10번으로부터 24번까지 최단거리는 : " << visited[24] - 1 << '\n';
    return 0;
}
