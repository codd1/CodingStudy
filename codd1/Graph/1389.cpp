#include <iostream>
#include <climits>		// INT_MAX
#include <vector>

#define MAX 101

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;		// N: ������ ��, M: ģ�� ������ ��
	cin >> N >> M;

	int INF = INT_MAX;
	int distance[MAX][MAX];

	fill(distance[1], distance[MAX], INF);

	int A, B;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;

		// A�� B�� ģ���̸� B�� A�� ģ���̴�.
		distance[A][B] = 1;
		distance[B][A] = 1;
	}

	for (int i = 1; i <= N; i++) {
		distance[i][i] = 0;
	}

	// �÷��̵�-����
	for (int k = 1; k <= N; k++) {
		for (int s = 1; s <= N; s++) {
			for (int e = 1; e <= N; e++) {
				if (distance[s][k] + distance[k][e] >= 0) {
					distance[s][e] = min(distance[s][e], distance[s][k] + distance[k][e]);
				}
			}
		}
	}

	int result[MAX] = { 0, };		// ������ ���� ������ �迭 (�ɺ� ������ ��: ��� ����� �ɺ� ������ ������ ���� �� ������ �ܰ��� ��)

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			result[i] += distance[i][j];
		}
	}

	int min = INF;
	int min_index = 0;

	for (int i = 1; i <= N; i++) {
		if (result[i] < min) {		// ������ ���� ���� ���� �����? (���� ���̶�� ���� ��ȣ�� ���� ��� ���)
			min = result[i];
			min_index = i;
		}
	}

	cout << min_index << "\n";

	return 0;
}