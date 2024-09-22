#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;		// N: 학생 수, M: 키 비교 횟수
	cin >> N >> M;

	vector<vector<int>> nodes(N + 1);
	vector<int> indegree(N + 1, 0);
	vector<int> sort;

	int A, B;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;

		nodes[A].push_back(B);
		indegree[B]++;
	}

	nodes;
	indegree;

	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			sort.push_back(i);

			for (int j = 0; j < nodes[i].size(); i++) {
				indegree[nodes[i][j]]--;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << sort[i] << "\n";
	}

	return 0;
}