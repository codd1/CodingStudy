#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(const string& str1, const string& str2) {
    return str1 + str2 > str2 + str1;
}

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> v_str;

    for (int i = 0; i < numbers.size(); i++) {
        v_str.push_back(to_string(numbers[i]));
    }

    sort(v_str.begin(), v_str.end(), compare);

    for (int i = 0; i < v_str.size(); i++) {
        answer += v_str[i];
    }

    if (answer[0] == '0') {
        answer = '0';
    }

    return answer;
}