#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int N, M;
vector<int> inputArray;

// 배열에서 찾는 값이 있으면 true, 없으면 false 반환
// 이진탐색의 시간복잡도는 logN
bool Binary_Search(int start, int end, int findNum) {


	while (start <= end) {
		int mid = (start + end) / 2;

		if (inputArray[mid] == findNum) {
			return true;
		}
		if (inputArray[mid] < findNum) {
			start = mid + 1; // target 은 오른쪽에 있음.
		}
		else {
			end = mid - 1; // target 은 왼쪽에 있음.
		}
	}
	return false;

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0;i < N;i++) {
		int a;
		cin >> a;
		inputArray.push_back(a);
	}

	// 입력값 오름차순으로 정렬
	sort(inputArray.begin(), inputArray.end());

	cin >> M;

	for (int i = 0;i < M;i++) {
		int a;
		cin >> a;
		if (Binary_Search(0, N - 1, a)) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
	return 0;

}