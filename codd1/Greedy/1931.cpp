#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool compareBySecond(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) {		// �� ���� second�� ���� ���
		return a.first < b.first;	// first�� �������� �������� ����
	}
	return a.second < b.second;
}

int main() {
	int N;			// ȸ���� ��
	int count = 0;	// ������ �� �ִ� ȸ���� ����
	vector<pair<int, int>> meeting;		// map�� �ߺ� �Է��� �ȵ�

	cin >> N;

	int start, end;
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		meeting.push_back(make_pair(start, end));
	}

	sort(meeting.begin(), meeting.end(), compareBySecond);	// second�� �������� �������� ����

	int previous_end = 0;		// ������ ����� ȸ�� �ð�
	for (auto i = meeting.begin(); i != meeting.end(); i++) {
		start = i->first;

		if (previous_end <= start) {	// ���� ȸ�� ���� �ð��� ������ ����� ȸ�� �ð����� ũ�ų� ���ٸ�
			count++;					// ȸ�Ǹ� ������ �� �ְ�
			previous_end = i->second;	// ȸ�ǰ� ����ǹǷ� ����� ȸ�� �ð����� �ٲ��ش�.
		}
	}

	cout << count << endl;

	return 0;
}