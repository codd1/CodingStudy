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

    v.push_back(stoi(str));     // ������ ������ ������ �����Ƿ� �ݺ����� ���� �Ŀ� �߰����ش�.

    sort(v.begin(), v.end());

    answer += to_string(v[0]) + " " + to_string(v[v.size() - 1]);     // ���ĵ� ���Ϳ��� ù ��° ��(�ּҰ�), ������ ��(�ִ밪)�� ����Ѵ�

    return answer;
}