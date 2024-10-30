#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;

    int i = 0, j = 0;

    for (; section[i] + m - 1 <= n && i < section.size(); i++) {
        answer++;
        for (j = i; section[j] <= section[i] + m - 1 && j < section.size(); j++) {
            //cout << section[j] << " <= " << section[i]+m-1<<endl;
        }

        j -= 1;     // ���� �ݺ������� �������� �����鼭 j++ �����Ƿ� �ٽ� -1 ���ش�.
        i = j;
    }

    if (i < section.size()) {       // ���� ������ �ϳ� �����ִٸ� ĥ�ؾ��ϴ� Ƚ�� �߰�
        answer++;
    }

    return answer;
}