#include <iostream>

using namespace std;

void preorder(char tree[27][2], int now) {
	if (now == -1) {
		return;
	}

	cout << (char)(now + 'A');

	preorder(tree, tree[now][0]);	// ���� �ڽ� ��� Ž��
	preorder(tree, tree[now][1]);	// ������ �ڽ� ��� Ž��
}

void inorder(char tree[27][2], int now) {
	if (now == -1) {
		return;
	}

	inorder(tree, tree[now][0]);	// ���� �ڽ� ��� Ž��

	cout << (char)(now + 'A');

	inorder(tree, tree[now][1]);	// ������ �ڽ� ��� Ž��
}

void postorder(char tree[27][2], int now) {
	if (now == -1) {
		return;
	}

	postorder(tree, tree[now][0]);	// ���� �ڽ� ��� Ž��
	postorder(tree, tree[now][1]);	// ������ �ڽ� ��� Ž��

	cout << (char)(now + 'A');
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;		// ���� Ʈ���� ��� ���� (1<=N<=26)
	cin >> N;

	// Ʈ�� ���� �����
	char tree[27][2] = {'\0',};

	char parent, left, right;
	for (int i = 0; i < N; i++) {
		cin >> parent >> left >> right;

		parent = parent - 'A';		// index�� ��ȯ�ϱ� ����

		if (left == '.') {			// �ڽ� ��尡 ���� ���, -1�� ����
			tree[parent][0] = -1;
		}
		else {
			tree[parent][0] = left - 'A';
		}
		
		if (right == '.') {
			tree[parent][1] = -1;
		}
		else {
			tree[parent][1] = right - 'A';
		}
	}

	preorder(tree, 0);		// ���� ��ȸ
	cout << "\n";

	inorder(tree, 0);		// ���� ��ȸ
	cout << "\n";

	postorder(tree, 0);		// ���� ��ȸ
	cout << "\n";

	return 0;
}