#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> maps) {
    vector<int> answer;

    queue<pair<int, int>> q;        // pair<x좌표, y좌표>
    pair<int, int> front = q.front();

    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false));     // 방문 배열도 2차원으로 표현

    int sum = 0;
    int x, y;

    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].size(); j++) {
            if (visited[i][j] == false) {       // 이미 방문한 곳인지 확인 후
                visited[i][j] = true;
                if (maps[i][j] != 'X') {        // 'X'라면 스킵
                    q.push(make_pair(i, j));
                    sum += maps[i][j] - '0';
                }
            }

            while (!q.empty()) {
                front = q.front();
                x = front.first;
                y = front.second;

                q.pop();

                if (x - 1 >= 0 && maps[x - 1][y] != 'X' && visited[x - 1][y] == false) {      // 상
                    q.push(make_pair(x - 1, y));        // BFS 큐에 추가
                    visited[x - 1][y] = true;           // 방문 처리
                    sum += maps[x - 1][y] - '0';        // 해당 섬에 저장된 값 더하기
                    //printf("sum += maps[%d][%d]\n", x-1, y);
                }

                if (x + 1 <= maps.size() - 1 && maps[x + 1][y] != 'X' && visited[x + 1][y] == false) {      // 하
                    q.push(make_pair(x + 1, y));
                    visited[x + 1][y] = true;
                    sum += maps[x + 1][y] - '0';
                    //printf("sum += maps[%d][%d]\n", x+1, y);
                }

                if (y - 1 >= 0 && maps[x][y - 1] != 'X' && visited[x][y - 1] == false) {      // 좌
                    q.push(make_pair(x, y - 1));
                    visited[x][y - 1] = true;
                    sum += maps[x][y - 1] - '0';
                    //printf("sum += maps[%d][%d]\n", x, y-1);
                }

                if (y + 1 <= maps[x].size() - 1 && maps[x][y + 1] != 'X' && visited[x][y + 1] == false) {      // 우
                    q.push(make_pair(x, y + 1));
                    visited[x][y + 1] = true;
                    sum += maps[x][y + 1] - '0';
                    //printf("sum += maps[%d][%d]\n", x, y+1);
                }
            }

            if (sum > 0) {      // 더해진 값이 있다면 answer에 추가
                answer.push_back(sum);
                sum = 0;
            }
        }
    }

    sort(answer.begin(), answer.end());     // 문제 조건에 따라 오름차순 정렬

    if (answer.size() == 0) {       // 문제 조건에 따라 저장된 값이 없다면 -1 저장
        answer.push_back(-1);
    }

    return answer;
}