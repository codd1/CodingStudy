#include <string>
#include <vector>
#include <cctype>   // isupper(), islower()
#include <iostream>

using namespace std;

string solution(string s, int n) {
    string answer = "";

    for (int i = 0; i < s.size(); i++) {
        if (islower(s[i])) {          // 소문자일 경우,
            if (s[i] + n > 122) {     // 소문자의 범위를 벗어날 경우(z 이상),
                answer += (char)(s[i] + n - 26);
            }
            else {
                answer += (char)(s[i] + n);
            }
        }
        else if (isupper(s[i])) {   // 대문자일 경우,
            if (s[i] + n > 90) {      // 대문자의 범위를 벗어날 경우(z 이상),
                answer += (char)(s[i] + n - 26);
            }
            else {
                answer += (char)(s[i] + n);
            }
        }
        else {     // 공백인 경우
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