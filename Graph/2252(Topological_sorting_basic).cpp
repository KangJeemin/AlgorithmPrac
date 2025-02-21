#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<vector<int>> ArrayVector(N + 1);
	vector<int> step(N + 1, 0);


	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		ArrayVector[a].push_back(b);
		step[b]++; // 진입 차수 채열 데이터 저장하기

	}

	queue<int> Q;// 위상정렬 수행 

	//진입 차수 만들기
	for (int i = 1;i <= N;i++) {
		if (step[i] == 0) {
			Q.push(i);
		}
	}

	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		cout << now << " "; // 진입 차수가 0이면 출력하기 

		for (int next : ArrayVector[now]) {
			step[next]--;
			if (step[next] == 0) {
				Q.push(next);
			}
		}
	}


	return 0;
}