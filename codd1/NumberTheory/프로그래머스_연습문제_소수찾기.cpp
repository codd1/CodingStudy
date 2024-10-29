#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;     // n은 2 이상이므로 소수 2를 포함하고 시작
    bool isPrime = true;

    vector<int> v(n + 1, 1);

    for (int i = 2; i <= n; i++) {
        for (int j = i * 2; j <= n; j += i) {
            if (v[j] != 0) {      // 아직 소수로 판별되지 않은 수라면,
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