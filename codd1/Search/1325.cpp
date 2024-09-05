#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>	// max_element

using namespace std;

// BFS�� ������ �Լ��� �����ϸ� �ð��ʰ� ����....

int main() {
	int N;		// ��ǻ�� ���� (���)
	int M;		// �ŷ� ���� ���� (����)

	cin >> N >> M;

	vector<vector<int>> network(N + 1);
	vector<bool> visited(N + 1, false);
	vector<int> count(N + 1, 0);

	int A, B;	// A�� B�� �ŷ��Ѵ�

	for (int i = 0; i < M; i++) {
		cin >> A >> B;

		network[A].push_back(B);
	}

	queue<int> q;

	for (int i = 1; i <= N; i++) {
		fill(visited.begin(), visited.end(), false);

		// BFS ����
		q.push(i);		// ���������� 1�� ��ǻ�ͺ��� ����
		visited[i] = true;
		int front = q.front();

		while (!q.empty()) {
			front = q.front();
			q.pop();

			for (int i = 0; i < network[front].size(); i++) {
				if (visited[network[front][i]] == false) {
					q.push(network[front][i]);
					visited[network[front][i]] = true;
					count[network[front][i]]++;		// Ž���Ǵ� ������ count++
				}
			}
		}
	}

	int max = *max_element(count.begin(), count.end());

	for (int i = 1; i <= N; i++) {
		if (count[i] == max) {
			cout << i << " ";
		}
	}

	return 0;
}