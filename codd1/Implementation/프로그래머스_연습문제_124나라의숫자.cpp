#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";

    if (n <= 2) {
        answer = to_string(n);

        return answer;
    }

    while (n > 0) {
        //printf("%d -> n % 3 = %d\n", n, n%3);
        switch (n % 3) {
        case 1:
            answer += "1";
            n -= 1;
            break;
        case 2:
            answer += "2";
            n -= 2;
            break;
        case 0:
            answer += "4";
            n -= 3;         // 124 ���󿡼��� 0�̶�� ���ڰ� �������� �ʱ� ������ 0�� ������ �� �ڸ� �ø����� �ذ� (�򿡼� -1)
            break;
        }

        n /= 3;
    }

    reverse(answer.begin(), answer.end());      // ������ �ڸ����� ����߱� ������ �������� string reverse

    return answer;
}