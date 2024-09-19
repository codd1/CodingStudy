#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;	// n: 도시의 개수, m: 도로의 개수
	cin >> n >> m;

	vector<int> indegree(n + 1, 0);
	vector<vector<pair<int,int>>> road(n + 1);
	vector<vector<pair<int,int>>> reverse_road(n + 1);		// road와 엣지의 방향이 반대
	vector<int> critical_path(n + 1, 0);	// 임계 경로

	// 지도를 그리는 사람들이 도착하는 시간 구하기
	queue<int> q;
	int front;

	int start, end, time;
	for (int i = 0; i < m; i++) {
		cin >> start >> end >> time;

		road[start].push_back(make_pair(end, time));	// 도착지와 소요 시간을 같이 저장하기 위해 pair 사용
		reverse_road[end].push_back(make_pair(start, time));	// 역방향 인접리스트도 저장
		indegree[end]++;
	}

	cin >> start >> end;
	q.push(start);		// 시작 도시에서부터 시작

	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0 && i != q.front()) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		front = q.front();
		q.pop();		// pop 되는 순서대로 정렬됨

		for (int i = 0; i < road[front].size(); i++) {
			indegree[road[front][i].first]--;

			critical_path[road[front][i].first] = max(critical_path[road[front][i].first], critical_path[front] + road[front][i].second);	// 이전 도시의 임계 경로 값 + 현재 도시의 소요 시간

			if (indegree[road[front][i].first] == 0) {
				q.push(road[front][i].first);
			}
		}
	}

	cout << critical_path[end] << "\n";		// 지도를 그리는 사람들이 도착하는 시간 출력

	// 1분도 쉬지 않고 달려야하는 도로의 수 구하기
	int count = 0;
	vector<int> visited(false, 0);

	q.push(end);
	front = q.front();

	while (!q.empty()) {
		front = q.front();
		q.pop();
		count++;

		for (int i = 0; i < reverse_road[front].size(); i++) {
			if (visited[reverse_road[front][i].first] == false) {
				if (critical_path[front] == critical_path[reverse_road[front][i].first] + reverse_road[front][i].second) {
					q.push(reverse_road[front][i].first);
				}

				visited[reverse_road[front][i].first] = true;
			}
		}
	}

	cout << count << "\n";

	return 0;
}