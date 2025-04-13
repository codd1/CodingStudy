#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	vector<int> bottle(3);	// 각각 부피가 A, B, C 리턴인 3개의 물통
	vector<vector<bool>> visited(201, vector<bool>(201, false));

	vector<int> sender = { 0,0,1,1,2,2 };
	vector<int> receiver = { 1,2,0,2,0,1 };
	vector<bool> answer(201);

	cin >> bottle[0] >> bottle[1] >> bottle[2];

	// BFS
	queue<pair<int, int>> q;

	q.push(make_pair(0, 0));
	visited[0][0] = true;
	answer[bottle[2]] = true;

	pair<int, int> front = q.front();
	
	int A, B, C;
	vector<int> next;

	while (!q.empty()) {
		front = q.front();
		q.pop();

		A = front.first;
		B = front.second;
		C = bottle[2] - A - B;		// C = 전체 물의 양 - A - B

		for (int i = 0; i < 6; i++) {
			next = { A,B,C };
			next[receiver[i]] += next[sender[i]];		// 받는 물통에 보내려는 물통의 값 더하기
			next[sender[i]] = 0;						// 물을 보냈으므로 보낸 물통의 값은 0이 됨

			if (next[receiver[i]] > bottle[receiver[i]]) {	// 대상 물통의 용량보다 물이 많아 넘칠 때
				next[sender[i]] = next[receiver[i]] - bottle[receiver[i]];		// 초과하는 만큼 다시 이전 물통에 넣음
				next[receiver[i]] = bottle[receiver[i]];	// 대상 물통은 최대로 채움
			}

			if (visited[next[0]][next[1]] == false) {
				visited[next[0]][next[1]] = true;
				q.push(make_pair(next[0], next[1]));

				if (next[0] == 0) {		// A 물통이 비어있을 때 C 물통의 물의 양을 답에 추가
					answer[next[2]] = true;
				}
			}
		}
	}

	for (int i = 0; i < 201; i++) {
		if (answer[i]) {		// 정답에 추가(true)된 답을 찾아 오름차순 출력
			cout << i << " ";
		}
	}

	return 0;
}