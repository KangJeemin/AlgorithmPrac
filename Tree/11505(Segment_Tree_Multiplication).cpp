#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

#define Mod 1000000007

vector<long> Tree;
void setTree(int i);
long getMul(int a, int b);
void changeVal(int index, long val);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, K;
	cin >> N >> M >> K;
	int treeHeight = 0;
	int length = N;

	while (length != 0) {
		length /= 2;
		treeHeight++;
	}
	int treeSize = pow(2, treeHeight + 1);
	int leftNodeStartIndex = treeSize / 2 - 1;
	Tree.resize(treeSize + 1, 1);

	// 데이터를 리프 노드에 입력 받기
	for (int i = leftNodeStartIndex + 1; i <= leftNodeStartIndex + N;i++) {
		cin >> Tree[i];
	}

	setTree(treeSize - 1);

	for (int i = 0;i < M + K;i++) {
		int a, s, e;
		cin >> a >> s >> e;
		if (a == 1) {
			changeVal(s + leftNodeStartIndex, e);
		}
		else if (a == 2) {
			cout << getMul(s + leftNodeStartIndex, e + leftNodeStartIndex) << '\n';
		}

	}

	return 0;
}

void setTree(int i) {

	while (i != 1) {
		Tree[i / 2] *= (Tree[i]) % Mod;
		i--;
	}
}
void changeVal(int index, long val) {
	Tree[index] = val;

	while (index > 1) {
		index /= 2;
		Tree[index] = (Tree[index * 2] % Mod) * (Tree[index * 2 + 1] % Mod);
	}
}
long getMul(int s, int e) { // 구간 최소 연산 함수
	long returnV = 1;
	while (s <= e) {
		if (s % 2 == 1) {
			returnV = (returnV * Tree[s]) % Mod;
			s++;
		}
		if (e % 2 == 0) {
			returnV = (returnV * Tree[e]) % Mod;
			e--;
		}
		s /= 2;
		e /= 2;
	}

	return returnV;

}

