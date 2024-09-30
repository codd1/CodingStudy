#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int find_func(vector<int>& union_find, int num) {					// find
	if (union_find[num] != num) {
		return find_func(union_find, union_find[num]);
	}
	else {
		return num;
	}
}

void union_func(vector<int>& union_find, int num1, int num2) {		// union
	num1 = find_func(union_find, num1);
	num2 = find_func(union_find, num2);

	if (num1 != num2) {
		union_find[num2] = num1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E;	// V: 정점의 개수, E: 간선의 개수
	cin >> V >> E;

	vector<int> union_find(V + 1);
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;	// 첫 번째 요소를 기준으로 오름차순 정렬

	for (int i = 1; i <= V; i++) {		// 유니온파인드 배열 초기화
		union_find[i] = i;
	}

	int A, B, C;	// A번 정점과 B번 정점이 가중치 C인 간선으로 연결되어있음
	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;

		q.push(make_tuple(C, A, B));	// 첫 번째 요소를 기준으로 정렬하므로 맨 앞에 가중치인 C가 들어감
	}

	int connected_edge = 0;		// 연결된 엣지 개수 (연결된 엣지 개수가 V - 1이 되면 종료)
	int sum = 0;
	while (connected_edge < V - 1) {
		if (find_func(union_find, get<1>(q.top())) != find_func(union_find, get<2>(q.top()))) {		// 대표 노드가 같다면 두 노드를 연결했을 때 사이클이 만들어진다.
			union_func(union_find, get<1>(q.top()), get<2>(q.top()));	// 사이클이 만들어지지 않는 노드만 연결 (union)
			sum += get<0>(q.top());

			connected_edge++;
		}
		q.pop();
	}

	cout << sum << "\n";

	return 0;
}