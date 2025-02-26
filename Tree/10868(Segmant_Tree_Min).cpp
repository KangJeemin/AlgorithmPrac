#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>
using namespace std;

vector<int> Tree;
void setTree(int i);
int getMin(int a, int b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	int treeHeight = 0;
	int length = N;

	while (length != 0) {
		length /= 2;
		treeHeight++;
	}
	int treeSize = pow(2, treeHeight + 1);
	int leftNodeStartIndex = treeSize / 2 - 1;
	Tree.resize(treeSize + 1, INT_MAX);

	// 데이터를 리프 노드에 입력 받기
	for (int i = leftNodeStartIndex + 1; i <= leftNodeStartIndex + N;i++) {
		cin >> Tree[i];
	}

	setTree(treeSize - 1);

	for (int i = 0;i < M;i++) {
		int s, e;
		cin >> s >> e;
		cout << getMin(s + leftNodeStartIndex, e + leftNodeStartIndex) << '\n';
	}

	return 0;
}

void setTree(int i) {

	while (i != 1) {
		Tree[i / 2] = min(Tree[i], Tree[i / 2]);
		i--;
	}
}

int getMin(int s, int e) { // 구간 최소 연산 함수
	int returnV = INT_MAX;
	while (s <= e) {
		returnV = min(returnV, Tree[s]);
		returnV = min(returnV, Tree[e]);
		if (s % 2 == 1) {
			s++;
		}
		if (e % 2 == 0) {
			e--;
		}
		s /= 2;
		e /= 2;
	}

	return returnV;

}

