#include<iostream>
#include<queue>
using namespace std;

void BFS();

// 6가지 이동 케이스를 표현하기 위한 배열
static int Sender[] = { 0,0,1,1,2,2 };
static int Receiver[] = { 1,2,0,2,0,1 };

// A B의 용량만 있으면 C의 용량이 고정되므로 2개로만 체크 가능
static bool visited[201][201];
static bool answer[201];
static int now[3]; // A B C 물의 양을 저장하는 배열


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> now[0] >> now[1] >> now[2];
	BFS();


	// 오름차순으로 C의 값 출력
	for (int i = 0; i < 201; i++) {
		if (answer[i]) {
			cout << i << " ";
		}
	}

}

void BFS() {

	// 초기설정
	queue<pair<int, int>> queue;
	queue.push({ 0,0 });

	// A=0, B=0  방문표시
	visited[0][0] = true;
	// C=10  을 담을수 있는 용량표시
	answer[now[2]] = true;

	while (!queue.empty()) {
		pair<int, int> p = queue.front();
		queue.pop();
		int A = p.first;
		int B = p.second;
		int C = now[2] - A - B;  // C는 전체 물의 양에서 A와 B를 뺀 것
		// (A→B, A→C, B→A, B→C, C→A , C→B) 6개의 케이스로 이동 

		for (int k = 0;k < 6;k++) {
			int next[] = { A,B,C };
			next[Receiver[k]] += next[Sender[k]];
			next[Sender[k]] = 0;

			// 대상 물통의 용량보다 물이 많아 넘칠 때
			if (next[Receiver[k]] > now[Receiver[k]]) {

				// 초과하는 만큼 다시 이전 물통에 넣음
				next[Sender[k]] = next[Receiver[k]] - now[Receiver[k]];

				// 대상 물통은 최대로 채움
				next[Receiver[k]] = now[Receiver[k]];
			}

			if (!visited[next[0]][next[1]]) {
				visited[next[0]][next[1]] = true;
				queue.push({ next[0],next[1] });
				if (next[0] == 0) {
					answer[next[2]] = true;
				}
			}
		}



	}
}