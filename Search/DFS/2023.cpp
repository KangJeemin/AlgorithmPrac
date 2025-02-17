#include<iostream>
#include<vector>
#include<cmath> 
// sqrt 함수 사용하기 위한 헤더
using namespace std;

// DFS를 이용해 수를 1개씩 이어 붙히며 N자릿수까지 탐색한다.
// 이때 짝수일 경우 탐색하지 않는다.
// 첫째자리는 2부터 9까지 탐색한다
// 두번째자리부터 1부터 9까지 탐색한다.
// N자리수에 도달했다면 해당수가 소수인지 아닌지 반별한다.



int N;

bool checkSosu(int num) {
	for (int i = 2; i <= sqrt(num);i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

void DFS(int num, int jaritsu) {
	if (!checkSosu(num)) return;
	if (jaritsu == N) {
		cout << num << '\n';
		return;
	}
	int nextnum = num * 10;
	for (int i = 1;i <= 9;i++) {
		DFS(nextnum + i, jaritsu + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 2;i <= 9;i++) {
		DFS(i, 1);
	}


}