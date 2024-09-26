#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

void BFS(vector<vector<int>> map, int i, int j) {
	vector<bool> visited;

	queue<int> q;
	q.push(1);
	int front = q.front();

	while (!q.empty()) {
		q.pop();
		front = q.front();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;		// N x M
	cin >> N >> M;

	vector<vector<int>> map(N);

	int input;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> input;
			map[i].push_back(input);
		}
	}

	int land_index = 1;		// 1부터 땅 번호 표기 (1~6)
	

	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				BFS(map, i, j);
			}
		}
	}

	cout << endl << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}