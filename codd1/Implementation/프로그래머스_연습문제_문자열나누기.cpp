#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;

    int x_index = 0;    // x�� �ε���
    int x = 0;          // x�� ���� Ƚ��
    int not_x = 0;      // x�� �ƴ� �ٸ� ���ڵ��� ���� Ƚ��

    for (int i = 0; i < s.size(); i++) {
        if (s[x_index] == s[i]) {
            x++;
        }
        else {
            not_x++;
        }

        if (x == not_x) {   // x�� x�� �ƴ� �ٸ� ���ڵ��� ���� Ƚ���� ���� ���,
            answer++;

            x = 0;
            not_x = 0;
            x_index = i + 1;
        }
        //printf("%d - x = %d, not_x = %d\n",i, x, not_x);
    }

    if (x != 0 || not_x != 0 || s.size() % 2 == 1) {    // ���� ���ڿ��� �ִٸ� answer++
        answer++;
    }

    return answer;
}