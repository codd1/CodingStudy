#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> maps) {
    vector<int> answer;

    queue<pair<int, int>> q;        // pair<x��ǥ, y��ǥ>
    pair<int, int> front = q.front();

    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false));     // �湮 �迭�� 2�������� ǥ��

    int sum = 0;
    int x, y;

    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].size(); j++) {
            if (visited[i][j] == false) {       // �̹� �湮�� ������ Ȯ�� ��
                visited[i][j] = true;
                if (maps[i][j] != 'X') {        // 'X'��� ��ŵ
                    q.push(make_pair(i, j));
                    sum += maps[i][j] - '0';
                }
            }

            while (!q.empty()) {
                front = q.front();
                x = front.first;
                y = front.second;

                q.pop();

                if (x - 1 >= 0 && maps[x - 1][y] != 'X' && visited[x - 1][y] == false) {      // ��
                    q.push(make_pair(x - 1, y));        // BFS ť�� �߰�
                    visited[x - 1][y] = true;           // �湮 ó��
                    sum += maps[x - 1][y] - '0';        // �ش� ���� ����� �� ���ϱ�
                    //printf("sum += maps[%d][%d]\n", x-1, y);
                }

                if (x + 1 <= maps.size() - 1 && maps[x + 1][y] != 'X' && visited[x + 1][y] == false) {      // ��
                    q.push(make_pair(x + 1, y));
                    visited[x + 1][y] = true;
                    sum += maps[x + 1][y] - '0';
                    //printf("sum += maps[%d][%d]\n", x+1, y);
                }

                if (y - 1 >= 0 && maps[x][y - 1] != 'X' && visited[x][y - 1] == false) {      // ��
                    q.push(make_pair(x, y - 1));
                    visited[x][y - 1] = true;
                    sum += maps[x][y - 1] - '0';
                    //printf("sum += maps[%d][%d]\n", x, y-1);
                }

                if (y + 1 <= maps[x].size() - 1 && maps[x][y + 1] != 'X' && visited[x][y + 1] == false) {      // ��
                    q.push(make_pair(x, y + 1));
                    visited[x][y + 1] = true;
                    sum += maps[x][y + 1] - '0';
                    //printf("sum += maps[%d][%d]\n", x, y+1);
                }
            }

            if (sum > 0) {      // ������ ���� �ִٸ� answer�� �߰�
                answer.push_back(sum);
                sum = 0;
            }
        }
    }

    sort(answer.begin(), answer.end());     // ���� ���ǿ� ���� �������� ����

    if (answer.size() == 0) {       // ���� ���ǿ� ���� ����� ���� ���ٸ� -1 ����
        answer.push_back(-1);
    }

    return answer;
}