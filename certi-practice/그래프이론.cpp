#include <iostream>
#include <vector>
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
