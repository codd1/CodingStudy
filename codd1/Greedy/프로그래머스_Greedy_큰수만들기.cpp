#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    char digit;

    for (int i = 0; i < number.size(); i++) {
        digit = number[i];

        // ������ ������ ���ڰ� ���� ���ں��� �۰�, ������ Ƚ���� �����ִٸ�
        while (!answer.empty() && answer.back() < digit && k > 0) {
            answer.pop_back();   // ������ ������ ���ڸ� ����
            k--;                // ���� Ƚ�� ����
        }

        answer += digit;
    }

    // Ž���� �������� ������ Ƚ���� ���� �ִٸ� �ڿ������� ����
    while (k > 0) {
        answer.pop_back();
        k--;
    }

    // ���ÿ� ���� ���ڵ��� ���ļ� ��� ��ȯ
    return answer;
}


int main() {
    cout << solution("1924", 2) << endl;            // "94"
    cout << solution("4177252841", 4) << endl;      // "775841"
}