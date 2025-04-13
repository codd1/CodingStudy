#include <iostream>
#include <climits>		// INT_MAX
#include <algorithm>	// fill()

#define MAX 101

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;	// n: 도시의 개수, m: 버스의 개수
	cin >> n >> m;

	int INF = INT_MAX;
	int distance[MAX][MAX];		// 도시의 최대 개수 100개

	fill(distance[1], distance[MAX], INF);

	for (int i = 1; i <= n; i++) {
		distance[i][i] = 0;		// 자기 자신에게 가는 경우는 cost == 0 ((1,1), (2,2), ... )
	}

	int start, end, cost;
	for (int i = 0; i < m; i++) {
		cin >> start >> end >> cost;

		distance[start][end] = min(distance[start][end], cost);		// 시작 도시와 도착 도시를 연결하는 노선은 1개가 아닐 수 있다. (그렇기 때문에 더 cost가 작은 값으로 저장한다)
	}

	for (int k = 1; k <= n; k++) {
		for (int s = 1; s <= n; s++) {
			for (int e = 1; e <= n; e++) {
				if (distance[s][k] + distance[k][e] >= 0) {	// INT_MAX + @를 하면 INT_MIN 값이 나오게 되어서 따로 조건 추가
					distance[s][e] = min(distance[s][e], distance[s][k] + distance[k][e]);
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (distance[i][j] == INF) {	// i에서 j로 갈 수 없을 때는 0을 출력한다.
				cout << 0 << " ";
			}
			else {
				cout << distance[i][j] << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}