#include <iostream>
#include <vector>

using namespace std;

// �̺� �׷���: �� ���տ� ���� ��峢�� ���� �������� �ʴ� �� �������� �׷����� ��带 ���� �� �ִ� �׷���

void DFS(vector<vector<int>> nodes, vector<int>& set, vector<bool>& visited, int num, bool& isCycle) {
	int nextNode;		// ���� ��� (����: ���� ���� num)

	visited[num] = true;

	for (int i = 0; i < nodes[num].size(); i++) {
		nextNode = nodes[num][i];
		if (visited[nextNode] == false) {
			set[nextNode] = (set[num] + 1) % 2;		// ������ ���� ���� ������ �ƴϹǷ� ���� ���� �ٸ� �������� ó��
													// ���ʴ�� ���� �迭�� A, B, A, B ������� �ִ´ٰ� ����

			DFS(nodes, set, visited, nextNode, isCycle);
		}
		else if (set[num] == set[nextNode]) {
			isCycle = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K;		// �׽�Ʈ ���̽� ���� K
	int V, E;	// ��� ���� V, ���� ���� E

	cin >> K;

	vector<vector<int>> nodes;		// ��������Ʈ
	vector<int> set;		// �̺� �׷��� ����
	vector<bool> visited;	// �湮 �迭
	bool isCycle = true;	// ����Ŭ�� �ִ���? (�ִٸ� �̺� �׷��� X)

	int node1, node2;	// �Է¿� ����
	for (int i = 0; i < K; i++) {
		cin >> V >> E;

		// ���� ũ��, �� �ʱ�ȭ
		isCycle = true;
		nodes.resize(V + 1);
		set.resize(V + 1);
		visited.resize(V + 1);

		for (int j = 1; j <= E; j++) {
			cin >> node1 >> node2;

			nodes[node1].push_back(node2);		// ��������Ʈ ����
			nodes[node2].push_back(node1);
		}

		for (int j = 1; j <= V; j++) {
			if (isCycle) {
				DFS(nodes, set, visited, j, isCycle);
			}
			else {
				break;		// ����Ŭ�� �ִ� ���, �ٷ� ����
			}
		}

		if (isCycle) {
			cout << "YES" << "\n";		// �̺� �׷���
		}
		else {
			cout << "NO" << "\n";		// �̺� �׷��� �ƴ�.
		}

		// �ʱ�ȭ
		for (int j = 0; j <= V; j++) {
			nodes[j].clear();
			visited[j] = false;
			set[j] = 0;
		}
	}

	return 0;
}