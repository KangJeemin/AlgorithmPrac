#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> map;
vector<int> parentNode;
vector<int> visitLocation;
int N, M;

int find(int a) {

	/*if (a != parentNode[a]) {
		parentNode[a] = find(parentNode[a]);
	}
	return parentNode[a];*/

	if (a == parentNode[a]) {
		return a;
	}
	else {
		return parentNode[a] = find(parentNode[a]);
	}
}

void unionF(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		parentNode[b] = a;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	parentNode.resize(N + 1, 0);
	map.resize(N + 1, vector<int>(N + 1, 0));
	visitLocation.resize(M + 1, 0);

	// ��ǥ��带 �ڱ� �ڽ����� �ʱ�ȭ
	for (int i = 1;i <= N;i++) {
		parentNode[i] = i;
	}
	// ���� ��� Ž������ ���ð� ����Ǹ� ���Ͽ� ����
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			int a;
			cin >> a;
			if (a > 0) {
				unionF(i, j);
			}
		}
	}
	// ���䵵��
	for (int i = 1;i <= M;i++) {
		cin >> visitLocation[i];
	}

	for (int i = 2;i <= M;i++) {
		if (find(visitLocation[1]) != find(visitLocation[i])) {
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";
	return 0;



}