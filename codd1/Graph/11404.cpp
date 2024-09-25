#include <iostream>
#include <climits>		// INT_MAX
#include <algorithm>	// fill()

#define MAX 101

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;	// n: ������ ����, m: ������ ����
	cin >> n >> m;

	int INF = INT_MAX;
	int distance[MAX][MAX];		// ������ �ִ� ���� 100��

	fill(distance[1], distance[MAX], INF);

	for (int i = 1; i <= n; i++) {
		distance[i][i] = 0;		// �ڱ� �ڽſ��� ���� ���� cost == 0 ((1,1), (2,2), ... )
	}

	int start, end, cost;
	for (int i = 0; i < m; i++) {
		cin >> start >> end >> cost;

		distance[start][end] = min(distance[start][end], cost);		// ���� ���ÿ� ���� ���ø� �����ϴ� �뼱�� 1���� �ƴ� �� �ִ�. (�׷��� ������ �� cost�� ���� ������ �����Ѵ�)
	}

	for (int k = 1; k <= n; k++) {
		for (int s = 1; s <= n; s++) {
			for (int e = 1; e <= n; e++) {
				if (distance[s][k] + distance[k][e] >= 0) {	// INT_MAX + @�� �ϸ� INT_MIN ���� ������ �Ǿ ���� ���� �߰�
					distance[s][e] = min(distance[s][e], distance[s][k] + distance[k][e]);
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (distance[i][j] == INF) {	// i���� j�� �� �� ���� ���� 0�� ����Ѵ�.
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