#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int gN, gM;

// BFS�� ������ ���� �����Ѵ�. (�� ������ ��ȣ�� �ű�)
void BFS(vector<vector<int>>& map, vector<vector<bool>>& visited, int i, int j, int land_index);

// �ٸ� ������ ������ �� �ִ� �ٸ��� ã�Ƽ� ���� ����Ʈ�� �߰�
void Add_bridge(priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>& q, vector<vector<int>>& map, int i, int j);

// �ּ� ���� Ʈ���� Ǯ�� ���� ���Ͽ����ε�
int find_func(vector<int>& union_find, int num);
void union_func(vector<int>& union_find, int num1, int num2);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;		// N x M
	cin >> N >> M;

	gN = N;		// �� �Լ��鿡�� ���� �����ϱ� ���� �������� ����
	gM = M;

	vector<vector<int>> map(N);		// �Է� �� ���� (���� �� ����)

	int input;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> input;
			map[i].push_back(input);
		}
	}

	int land_index = 1;		// 1���� �� ��ȣ ǥ�� (1~6)
	vector<vector<bool>> visited(N, vector<bool>(M, false));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1 && visited[i][j] == false) {
				BFS(map, visited, i, j, land_index);
				land_index++;
			}
		}
	}

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] > 0) {	// �� �����̶��
				Add_bridge(q, map, i, j);
			}
		}
	}

	vector<int> union_find(land_index);

	for (int i = 1; i < land_index; i++) {
		union_find[i] = i;
	}

	int connected_edge = 0;
	int count = 0;

	while (!q.empty()) {
		tuple<int, int, int> top = q.top();
		q.pop();

		if (find_func(union_find, get<1>(top)) != find_func(union_find, get<2>(top))) {
			union_func(union_find, get<1>(top), get<2>(top));
			count += get<0>(top);
			connected_edge++;
		}
	}

	if (connected_edge == land_index - 2) {
		cout << count << "\n";
	}
	else {
		cout << -1 << "\n";
	}

	return 0;
}

void BFS(vector<vector<int>>& map, vector<vector<bool>>& visited, int i, int j, int land_index) {
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));

	map[i][j] = land_index;
	visited[i][j] = true;

	pair<int, int> front = q.front();

	while (!q.empty()) {
		front = q.front();
		q.pop();

		if (front.first > 0 && visited[front.first - 1][front.second] == false) {		// �� ������ ���� �湮���� ���� ���̰�
			if (map[front.first - 1][front.second] == 1) {			// ���̶��
				map[front.first - 1][front.second] = land_index;
				q.push(make_pair(front.first - 1, front.second));
				visited[front.first - 1][front.second] = true;
			}
		}

		if (front.first + 1 < gN && visited[front.first + 1][front.second] == false) {		// �Ʒ� ������ ���� �湮���� ���� ���̰�
			if (map[front.first + 1][front.second] == 1) {			// ���̶��
				map[front.first + 1][front.second] = land_index;
				q.push(make_pair(front.first + 1, front.second));
				visited[front.first + 1][front.second] = true;
			}
		}

		if (front.second > 0 && visited[front.first][front.second - 1] == false) {		// ���� ������ ���� �湮���� ���� ���̰�
			if (map[front.first][front.second - 1] == 1) {			// ���̶��
				map[front.first][front.second - 1] = land_index;
				q.push(make_pair(front.first, front.second - 1));
				visited[front.first][front.second - 1] = true;
			}
		}

		if (front.second + 1 < gM && visited[front.first][front.second + 1] == false) {		// ������ ������ ���� �湮���� ���� ���̰�
			if (map[front.first][front.second + 1] == 1) {			// ���̶��
				map[front.first][front.second + 1] = land_index;
				q.push(make_pair(front.first, front.second + 1));
				visited[front.first][front.second + 1] = true;
			}
		}
	}
}

void Add_bridge(priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>& q, vector<vector<int>>& map, int i, int j) {
	int temp_i = i - 1;
	int temp_j = j;

	int distance = 0;

	while (temp_i >= 0 && map[temp_i][j] != map[i][j]) {		// ��
		if (map[temp_i][j] == 0) {
			temp_i--;
			distance++;
		}
		else if (map[temp_i][j] > 0) {
			if (distance > 1) {		// �Ÿ��� 1 ������ �ٸ��� �������� ���� (���� ����)
				q.push(make_tuple(distance, map[i][j], map[temp_i][j]));	// �Ÿ�(����ġ), ��߼�, ������ (����ġ�� �������� ���ĵǵ��� ù ��° ���� ����ġ�� ����)
			}
			break;
		}
	}

	temp_i = i + 1;
	temp_j = j;

	distance = 0;

	while (temp_i < gN && map[temp_i][j] != map[i][j]) {		// ��
		if (map[temp_i][j] == 0) {
			temp_i++;
			distance++;
		}
		else if (map[temp_i][j] > 0) {
			if (distance > 1) {
				q.push(make_tuple(distance, map[i][j], map[temp_i][j]));
			}
			break;
		}
	}

	temp_i = i;
	temp_j = j - 1;

	distance = 0;

	while (temp_j >= 0 && map[i][temp_j] != map[i][j]) {		// ��
		if (map[i][temp_j] == 0) {
			temp_j--;
			distance++;
		}
		else if (map[i][temp_j] > 0) {
			if (distance > 1) {
				q.push(make_tuple(distance, map[i][j], map[i][temp_j]));
			}
			break;
		}
	}

	temp_i = i;
	temp_j = j + 1;

	distance = 0;

	while (temp_j < gM && map[i][temp_j] != map[i][j]) {		// ��
		if (map[i][temp_j] == 0) {
			temp_j++;
			distance++;
		}
		else if (map[i][temp_j] > 0) {
			if (distance > 1) {
				q.push(make_tuple(distance, map[i][j], map[i][temp_j]));
			}
			break;
		}
	}
}

int find_func(vector<int>& union_find, int num) {
	if (union_find[num] != num) {
		return find_func(union_find, union_find[num]);
	}
	else {
		return union_find[num];
	}
}

void union_func(vector<int>& union_find, int num1, int num2) {
	num1 = find_func(union_find, num1);
	num2 = find_func(union_find, num2);

	if (num1 != num2) {
		union_find[num2] = num1;
	}
}