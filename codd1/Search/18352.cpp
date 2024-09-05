#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int N;		// ������ ����
	int M;		// ������ ����
	int K;		// �Ÿ� ���� K
	int X;		// ��� ������ ��ȣ X

	cin >> N >> M >> K >> X;

	vector<vector<int>> nodes(N + 1);
	vector<bool> visited(N + 1, false);
	vector<int> distance(N + 1, 0);	// �ִ� �Ÿ�

	int A, B;	// ���� A, B
	for (int i = 0; i < M; i++) {
		cin >> A >> B;

		nodes[A].push_back(B);		// �ܹ��� ����
	}

	queue<int> q;
	q.push(X);		// X ���ú��� ���
	visited[X] = true;
	int front = q.front();

	// BFS
	while (!q.empty()) {
		front = q.front();
		q.pop();

		for (int i = 0; i < nodes[front].size(); i++) {
			if (visited[nodes[front][i]] == false) {
				q.push(nodes[front][i]);
				visited[nodes[front][i]] = true;
				distance[nodes[front][i]] = distance[front] + 1;
			}
		}
	}

	bool isDistanceK = false;

	for (int i = 0; i <= N; i++) {
		if (distance[i] == K) {
			cout << i << endl;
			isDistanceK = true;
		}
	}

	if (isDistanceK == false) {		// �ִ� �Ÿ��� K�� ���ð� �ϳ��� �������� ������ -1�� ���
		cout << -1 << endl;
	}

	return 0;
}