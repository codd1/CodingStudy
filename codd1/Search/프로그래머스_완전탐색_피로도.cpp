#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool visited[8] = { false, };
int answer = 0;

void dfs(vector<vector<int>> dungeons, int k, int count) {
    for (int i = 0; i < dungeons.size(); i++) {
        if (visited[i] == false) {
            if (dungeons[i][0] <= k) {
                visited[i] = true;
                dfs(dungeons, k - dungeons[i][1], count + 1);
                visited[i] = false;     // ���� Ž���� ���� �湮�� ��带 �ٽ� �̹湮 ǥ��
            }
        }
    }
    answer = max(answer, count);    // count �ִ��� �������� ����
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(dungeons, k, 0);
    return answer;
}