#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> v;

    string str = "";
    int num = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            num = stoi(str);
            v.push_back(num);
            str = "";
        }
        else {
            str += s[i];
        }
    }

    v.push_back(stoi(str));     // 마지막 정수는 공백이 없으므로 반복문이 끝난 후에 추가해준다.

    sort(v.begin(), v.end());

    answer += to_string(v[0]) + " " + to_string(v[v.size() - 1]);     // 정렬된 벡터에서 첫 번째 값(최소값), 마지막 값(최대값)을 사용한다

    return answer;
}