#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// �׷��� ǥ������ �������, ��������Ʈ�� �ִ�
// ������� (��Ī��)
bool a[4][4] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 0},
    {1, 0, 0, 0},
};
//1��.
//������ 0�� ���� 9������ 10���� ��尡 �ִ�. 1 - 2 / 1 - 3 / 3 - 4 ��� ��ΰ� �ִ�. (1���� 2��, 1���� 3��, 3���� 4���� ����Ǿ��ִ�.)
//�̸� ������ķ� ǥ���Ѵٸ� ?
//0������ �湮���� ��带 ã�� �ش� ������ �湮, ����� ��带 �̾ �湮�ؼ� ����ϴ� ����Լ��� ����� �ʹٸ� ��� �ؾ��ұ� ? ����, ������ �湮�ϰ� �ٽ� �湮���� �ʰ� ������� ��� �ؾ��ұ� ?

//��
const int V = 10;
bool a[V][V], visited[V];
void go(int from)
{
    visited[from] = 1;
    cout << from << "/n"; // �湮������ ���
    for (int i = 0; i < V; i++)
    {
        if (visited[i]) continue;
        if (a[from][i])
        {
            go(i); // a�� ���� �����ؾ� �湮
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


//��������Ʈ
//�������� �迭�� ���� ��
// 0 : 1,2,3 �� ����
// 1 : 0,2 ����
// 2 : 0,1 ����
// 3 : 0 �� ����
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

//-> ������ ��������Ʈ�� Ǯ�� ������ ��ķ� ���������� ��ķ� Ǯ��!

//��ǥ Ž��
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

//Q. 3 * 3 ���� �Է¹޾ƾ� ��. �� ���� 1�� 0���� �̷�����ְ� {0, 0}�� ������ 1���� �����Ѵ�.
//{0, 0}���� 4������ �������� ��ĭ�� Ž���س����� �湮�� ������ �ٽ� �湮���� ������ �湮�ϴ� ��ǥ�� ����ϴ� �ڵ�.
//0�� �� �� ���� ����. 1�� �� �� �ִ� ������ �����Ͻÿ�.

const int n = 3;
int a[n][n];
int visited_[n][n] = { 0, };
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, -1, 0, 1 };
 
void go(int y, int x) {
    visited_[y][x] = 1;
    cout << y << " : " << x << "\n"; // �湮�� ��ǥ ���
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
// ���� u�� visited�� ������ �ٲٰ� u�� ����� v���� �湮�Ѵ� 
//DFS(u, adj)
// u.visited = true
//  for each v �� adj[u]
//    if v.visited == false
//      DFS(v, adj)

// ������Ʈ ã�� 
// ������Ʈ : �ʻ󿡼� ����� ������ �� ���̱� ������. 
// Q. ��ȭ�� �汸���̾�

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
            if (a[i][j] == 1 && !b_visited[i][j]) // ������ �湮���� �ʾҴٸ� ���ο� ���� ����
            { 
                ret++; b_dfs(i, j); // �� ���� �� ������ Ż����
            }
        }
    }
    cout << ret << '\n';
    return 0;
}

// BFS
// ���� ���̾ �ִ� �͵� ���� ����, ���̿켱Ž��, �ִܰŸ��˰���
// �����ڵ� 1
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

// �ٵ� ������ �ִܰŸ��� �Ϸ��� v.visited = true�� v.visited = u.visited + 1 �� ����
// �׷��� visited�� ó�����ۺ��� �ش� �������� ���µ� �ɸ� �ð��� ����

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
    cout << "10�����κ��� 24������ �ִܰŸ��� : " << visited[24] - 1 << '\n';
    return 0;
}
