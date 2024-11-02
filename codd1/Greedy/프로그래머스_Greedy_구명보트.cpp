#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end());

    int sum = 0;

    vector<bool> is_exist(people.size(), true);

    int i = 0;
    int j = people.size() - 1;

    while (i < j) {
        sum = people[i] + people[j];

        if (sum <= limit) {       // �� ���� �¿� �� �ִ� ���
            is_exist[j] = false;
            is_exist[i] = false;
            i++;
            j--;
        }
        else {                 // �� �� �¿� �� �ִ� ���
            is_exist[j] = false;
            j--;
        }

        answer++;
    }

    if (i == j) {     // �������� i == j���, �� ���� ���� ���̹Ƿ� �������� �߰�
        answer++;
    }

    return answer;
}