#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<string> split(string& record) {
    vector<string> s;
    string str;

    for (int i = 0; i < record.size(); i++) {
        if (record[i] == ' ') {
            s.push_back(str);
            str = "";
        }
        else {
            str += record[i];
        }
    }

    s.push_back(str);       // �������� �߰����� ���� ���ڿ� �߰�

    return s;
}

string find_user(string& uid, map<string, string>& m) {
    auto iter = m.find(uid);

    if (iter != m.end()) {        // map���� uid�� ã�� ���
        return iter->second;
    }
    else {
        return NULL;
    }
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> split_record;
    vector<pair<string, string>> v;
    map<string, string> m;

    for (int i = 0; i < record.size(); i++) {
        split_record = split(record[i]);

        if (record[i][0] == 'E') {        // Enter
            m[split_record[1]] = split_record[2];       // ���� Ű�� �����ص� ���� �ٸ��ٸ� ���� �ٲ�
            v.push_back(make_pair(split_record[0], split_record[1]));
        }
        else if (record[i][0] == 'L') {   // Leave
            v.push_back(make_pair(split_record[0], split_record[1]));
        }
        else if (record[i][0] == 'C') {   // Change
            m[split_record[1]] = split_record[2];
        }
    }

    string str;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].first == "Enter") {
            str = find_user(v[i].second, m) + "���� ���Խ��ϴ�.";
        }
        else if (v[i].first == "Leave") {
            str = find_user(v[i].second, m) + "���� �������ϴ�.";
        }
        answer.push_back(str);
    }

    return answer;
}

int main() {
    vector<string> record;
    vector<string> answer;

    record.assign({ "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" });
    answer.assign({ "Prodo���� ���Խ��ϴ�.", "Ryan���� ���Խ��ϴ�.", "Prodo���� �������ϴ�.", "Prodo���� ���Խ��ϴ�." });

    if (answer == solution(record)) {
        cout << "correct!" << endl;
    }
    else {
        cout << "falut" << endl;
    }
}