#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

vector<long> Tree;
void setTree(int i);
long getsum(int a, int b);
void changeVal(int a, long b);

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
	Tree.resize(treeSize + 1);

	// 데이터를 리프 노드에 입력 받기
	for (int i = leftNodeStartIndex + 1; i <= leftNodeStartIndex + N;i++) {
		cin >> Tree[i];
	}

	setTree(treeSize - 1);

	for (int i = 0;i < M + K;i++) {
		long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			changeVal(leftNodeStartIndex + b, c);
		}
		else if (a == 2) {
			cout << getsum(b + leftNodeStartIndex, c + leftNodeStartIndex) << '\n';
		}
	}

	return 0;
}

void setTree(int i) {

	while (i != 1) {
		Tree[i / 2] += Tree[i];
		i--;
	}
}

long getsum(int s, int e) { // 구간 합 연산 함수
	long partSum = 0;

	while (s <= e) {
		if (s % 2 == 1) {
			partSum += Tree[s];
			s++;
		}
		if (e % 2 == 0) {
			partSum += Tree[e];
			e--;
		}
		s /= 2;
		e /= 2;
	}
	return partSum;
}

void changeVal(int index, long val) {
	long dif = val - Tree[index];

	while (index > 0) {
		Tree[index] += dif;
		index /= 2;
	}

}