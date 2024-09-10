#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	vector<int> bottle(3);	// ���� ���ǰ� A, B, C ������ 3���� ����
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
		C = bottle[2] - A - B;		// C = ��ü ���� �� - A - B

		for (int i = 0; i < 6; i++) {
			next = { A,B,C };
			next[receiver[i]] += next[sender[i]];		// �޴� ���뿡 �������� ������ �� ���ϱ�
			next[sender[i]] = 0;						// ���� �������Ƿ� ���� ������ ���� 0�� ��

			if (next[receiver[i]] > bottle[receiver[i]]) {	// ��� ������ �뷮���� ���� ���� ��ĥ ��
				next[sender[i]] = next[receiver[i]] - bottle[receiver[i]];		// �ʰ��ϴ� ��ŭ �ٽ� ���� ���뿡 ����
				next[receiver[i]] = bottle[receiver[i]];	// ��� ������ �ִ�� ä��
			}

			if (visited[next[0]][next[1]] == false) {
				visited[next[0]][next[1]] = true;
				q.push(make_pair(next[0], next[1]));

				if (next[0] == 0) {		// A ������ ������� �� C ������ ���� ���� �信 �߰�
					answer[next[2]] = true;
				}
			}
		}
	}

	for (int i = 0; i < 201; i++) {
		if (answer[i]) {		// ���信 �߰�(true)�� ���� ã�� �������� ���
			cout << i << " ";
		}
	}

	return 0;
}