#include <iostream>

#define K_MAX 1'000'000'000

using namespace std;

long long D[201][201] = { 0, };		// 조합의 경우의 수

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;	// N: "a" 갯수, M: "z" 갯수
	cin >> N >> M;

	for (int i = 0; i <= 200; i++) {
		D[i][i] = 1;
		D[i][1] = i;
		D[i][0] = 1;
	}

	for (int i = 1; i <= 200; i++) {		// N + M
		for (int j = 1; j <= i; j++) {		// 고르는 수의 갯수가 전체 갯수(=N+M)를 넘을 수 없음
			D[i][j] = D[i - 1][j] + D[i - 1][j - 1];	// 점화식

			if (D[i][j] > K_MAX || D[i][j] < 0) {		// 오버플로우 방지를 위한 처리 (K_MAX는 문제에서 주어진 조건)
				D[i][j] = K_MAX;
			}
		}
	}

	int K;		// 몇 번째 문자열을 표현해야 하는지?
	cin >> K;

	if (D[N + M][M] < K) {		// 만약 규완이의 사전에 수록되어 있는 문자열의 개수가 K보다 작으면 -1을 출력한다.
		cout << -1;

		return 0;
	}

	long long T;		// 현재 자리 수에서 a를 선택했을 때 남은 문자로 만들 수 있는 모든 경우의 수

	// T와 K를 비교해 문자 선택

	int remainer_z = M;				// 남은 z 갯수
	int remainer_total = N + M;		// 남은 총 문자 갯수

	remainer_total--;	// 처음에 어쨋든 문자 하나를 선택하므로 1개 빼고 시작
	T = D[remainer_total][remainer_z];

	for (int i = 0; i < N + M; i++) {
		/*
			D[A][B] = 남은 총 문자 개수(A)에서 남은 z 개수(B)를 고르는 경우의 수

			남은 문자들로 만들 수 있는 경우의 수가 K 이상이라면,
			사전순으로 앞선 문자열들만으로도 K번째 문자열에 도달할 수 있음.
		*/
		if (D[remainer_total][remainer_z] >= K) {
			cout << "a";
		}
		else {		// D[remainer_total][remainer_z] < K
			cout << "z";

			remainer_z--;	// z를 하나 확정지었으므로 남은 z 총 갯수를 줄인다.
			K = K - T;		// K 값 업데이트
		}

		remainer_total--;	// 문자 하나를 확정지었으므로 남은 문자 총 개수를 줄인다.
		T = D[remainer_total][remainer_z];		// 바뀐 값으로 T 값 업데이트
	}

	return 0;
}