#include <iostream>
#include <climits>		// INT_MAX
#include <vector>

#define MAX 101

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;		// N: 유저의 수, M: 친구 관계의 수
	cin >> N >> M;

	int INF = INT_MAX;
	int distance[MAX][MAX];

	fill(distance[1], distance[MAX], INF);

	int A, B;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;

		// A와 B가 친구이면 B와 A도 친구이다.
		distance[A][B] = 1;
		distance[B][A] = 1;
	}

	for (int i = 1; i <= N; i++) {
		distance[i][i] = 0;
	}

	// 플로이드-워셜
	for (int k = 1; k <= N; k++) {
		for (int s = 1; s <= N; s++) {
			for (int e = 1; e <= N; e++) {
				if (distance[s][k] + distance[k][e] >= 0) {
					distance[s][e] = min(distance[s][e], distance[s][k] + distance[k][e]);
				}
			}
		}
	}

	int result[MAX] = { 0, };		// 베이컨 수를 저장할 배열 (케빈 베이컨 수: 모든 사람과 케빈 베이컨 게임을 했을 때 나오는 단계의 합)

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			result[i] += distance[i][j];
		}
	}

	int min = INF;
	int min_index = 0;

	for (int i = 1; i <= N; i++) {
		if (result[i] < min) {		// 베이컨 수가 가장 작은 사람은? (여러 명이라면 가장 번호가 작은 사람 출력)
			min = result[i];
			min_index = i;
		}
	}

	cout << min_index << "\n";

	return 0;
}