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

        if (sum <= limit) {       // 두 명을 태울 수 있는 경우
            is_exist[j] = false;
            is_exist[i] = false;
            i++;
            j--;
        }
        else {                 // 한 명만 태울 수 있는 경우
            is_exist[j] = false;
            j--;
        }

        answer++;
    }

    if (i == j) {     // 마지막에 i == j라면, 한 명이 남는 것이므로 마지막에 추가
        answer++;
    }

    return answer;
}