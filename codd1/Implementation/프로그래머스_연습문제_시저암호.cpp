#include <string>
#include <vector>
#include <cctype>   // isupper(), islower()
#include <iostream>

using namespace std;

string solution(string s, int n) {
    string answer = "";

    for (int i = 0; i < s.size(); i++) {
        if (islower(s[i])) {          // �ҹ����� ���,
            if (s[i] + n > 122) {     // �ҹ����� ������ ��� ���(z �̻�),
                answer += (char)(s[i] + n - 26);
            }
            else {
                answer += (char)(s[i] + n);
            }
        }
        else if (isupper(s[i])) {   // �빮���� ���,
            if (s[i] + n > 90) {      // �빮���� ������ ��� ���(z �̻�),
                answer += (char)(s[i] + n - 26);
            }
            else {
                answer += (char)(s[i] + n);
            }
        }
        else {     // ������ ���
            answer += " ";
        }
    }
    return answer;
}

int main() {
    string s = "a B z";
    int n = 4;

    string answer = "e F d";

    if (answer == solution(s, n)) {
        cout << "correct!" << endl;
    }
    else {
        cout << "falut" << endl;
    }
}