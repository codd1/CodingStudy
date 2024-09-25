#include <iostream>
#include <climits>

#define MAX 101

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;		// 노드의 개수
	cin >> N;

	int distance[MAX][MAX] = { 0, };

	for (int i = 1; i <= N; i++) {
		distance[i][i] = 0;
	}

	for (int s = 1; s <= N; s++) {
		for (int e = 1; e <= N; e++) {
			cin >> distance[s][e];		// 노드 s에서 e로 가는 경로가 있다면 1, 없다면 0 입력
		}
	}

	for (int k = 1; k <= N; k++) {
		for (int s = 1; s <= N; s++) {
			for (int e = 1; e <= N; e++) {
				if (distance[s][k] == 1 && distance[k][e] == 1) {	// s->k 경로가 있고, k->e 경로도 있는 경우
					distance[s][e] = 1;								// s->e 경로도 있는 것이다.
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << distance[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}