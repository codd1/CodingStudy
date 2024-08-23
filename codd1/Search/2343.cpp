#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;		// 강의 갯수
	int M;		// 블루레이 갯수

	cin >> N >> M;

	vector<int> lecture(N);
	vector<int> bluray(M, 0);
	int start = 0;
	int end = 0;
	int median = 0;

	for (int i = 0; i < N; i++) { 
		cin >> lecture[i];

		if (lecture[i] > start) {	// 강의 길이의 최댓값을 찾아서 start에 저장
			start = lecture[i];
		}

		end += lecture[i];
	}

	int bluray_index = 0;
	bool isPossible = true;

	while (start <= end) {
		bluray.assign(M, 0);			// 모두 0으로 초기화, 나머지 변수들도 초기화
		bluray_index = 0;				
		isPossible = true;
		median = (start + end) / 2;		// 이진 탐색을 위한 중앙값 찾기
	
		for (int i = 0; i < N; i++) {
			if ((bluray[bluray_index] + lecture[i]) > median) {
				bluray_index++;

				if (bluray_index == M) {		// 블루레이 갯수가 조건보다 많아질 경우,
					start = median + 1;			// start 값을 median +1 값으로 변경한다. (조건에 부합하지 않기 때문에)
					isPossible = false;
					break;
				}
			}
			bluray[bluray_index] += lecture[i];
		}

		if (isPossible) {		// 저장 가능하다면,
			end = median - 1;	// end 값을 median -1 값으로 변경한다. (최소 값을 찾으므로 median 이상은 볼 필요 없으니까)
		}
	}

	cout << start << endl;

	return 0;
}