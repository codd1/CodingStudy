#include <iostream>
#include <climits>

#define MAX 101

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;		// ����� ����
	cin >> N;

	int distance[MAX][MAX] = { 0, };

	for (int i = 1; i <= N; i++) {
		distance[i][i] = 0;
	}

	for (int s = 1; s <= N; s++) {
		for (int e = 1; e <= N; e++) {
			cin >> distance[s][e];		// ��� s���� e�� ���� ��ΰ� �ִٸ� 1, ���ٸ� 0 �Է�
		}
	}

	for (int k = 1; k <= N; k++) {
		for (int s = 1; s <= N; s++) {
			for (int e = 1; e <= N; e++) {
				if (distance[s][k] == 1 && distance[k][e] == 1) {	// s->k ��ΰ� �ְ�, k->e ��ε� �ִ� ���
					distance[s][e] = 1;								// s->e ��ε� �ִ� ���̴�.
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