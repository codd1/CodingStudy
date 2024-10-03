#include <iostream>

using namespace std;

class Node {		// Ʈ���� �ڷ� ���� ����� Ŭ����
public:
	Node* next[26];			// ���ĺ� �������� ũ�� 26�� �迭 ����
	bool isEnd = false;		// ������ ���ڿ� ���� ǥ��

	Node() {
		fill(next, next + 26, nullptr);
	}

	~Node() {
		for (int i = 0; i < 26; i++) {
			if (next[i] != nullptr) {
				delete next[i];
			}
		}
	}

	void insert(char* key) {	// ���ڿ� ���� �Լ�
		if (*key == 0) {
			isEnd = true;
		}
		else {
			int nextIndex = *key - 'a';

			if (next[nextIndex] == nullptr) {		// key ������ �ش��ϴ� ��尡 nullptr�̶��
				next[nextIndex] = new Node();		// �ű� ��� ����
			}

			next[nextIndex]->insert(key + 1);		// ���� ���ڿ�
		}
	}

	Node* find(char* key) {		// ���ڿ� ã�� �Լ�
		if (*key == 0) {
			return this;		// ������ ���ڿ��̶�� �ش� ���� ����
		}
		
		int nextIndex = *key - 'a';

		if (next[nextIndex] == nullptr) {
			return nullptr;
		} 

		return next[nextIndex]->find(key + 1);		// ���� ���ڿ�
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	// Ʈ���� �ڷ� ���� ���� (���� S)
	Node* root = new Node();
	char text[501];

	for (int i = 0; i < N; i++) {
		cin >> text;

		root->insert(text);
	}

	// Ʈ���� �ڷᱸ�� �˻�
	Node* result;
	int count = 0;

	for (int i = 0; i < M; i++) {
		cin >> text;

		result = root->find(text);

		if (result && result->isEnd) {		// ������ ��尡 �����ϰ�, isEnd == true���
			count++;						// ���� S�� ���ԵǴ� ���ڿ��� ã�� ���̹Ƿ� ī����
		}
	}

	cout << count << "\n";

	return 0;
}