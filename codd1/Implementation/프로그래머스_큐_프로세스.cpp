#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    queue<pair<int, int>> q;     // queue<�켱����, ��ġ>
    pair<int, int> front;

    for (int i = 0; i < priorities.size(); i++) {
        q.push(make_pair(priorities[i], i));
    }

    sort(priorities.begin(), priorities.end());
    int max_index = priorities.size() - 1;

    while (!q.empty()) {
        front = q.front();

        if (front.first < priorities[max_index]) {
            q.pop();
            q.push(make_pair(front.first, front.second));
        }
        else {     // front.first == max
            q.pop();
            answer++;

            if (front.second == location) {
                break;
            }

            max_index--;    // max ���� pop �����Ƿ� ���� max ������ ����
        }
    }

    return answer;
}

int main() {
    vector<int> priorities = { 1,1,9,1,1,1 };
    int location = 0;

    cout << solution(priorities, location) << endl;     // ����: 5
}