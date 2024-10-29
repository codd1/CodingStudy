#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;     // n�� 2 �̻��̹Ƿ� �Ҽ� 2�� �����ϰ� ����
    bool isPrime = true;

    vector<int> v(n + 1, 1);

    for (int i = 2; i <= n; i++) {
        for (int j = i * 2; j <= n; j += i) {
            if (v[j] != 0) {      // ���� �Ҽ��� �Ǻ����� ���� �����,
                v[j] = 0;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (v[i] != 0) {
            answer++;
        }
    }

    return answer;
}

int main() {
    int n = 10;
    int answer = 4;

    if (answer == solution(n)) {
        cout << "correct!" << endl;
    }
    else {
        cout << "falut" << endl;
    }
}