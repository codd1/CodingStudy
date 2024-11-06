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
                visited[i] = false;     // 완전 탐색을 위해 방문한 노드를 다시 미방문 표시
            }
        }
    }
    answer = max(answer, count);    // count 최댓값을 정답으로 저장
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(dungeons, k, 0);
    return answer;
}