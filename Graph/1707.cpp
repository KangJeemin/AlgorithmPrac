#include<iostream>
#include<vector>
using namespace std;

// �̺� �׷��� �Ǻ��ϱ�
vector<vector<int>> edge;
vector<bool> visited;
vector<int> checked;
bool flag;


void DFS(int edgeN) {

	visited[edgeN] = true;

	for (int i : edge[edgeN]) {
		if (!visited[i]) {
			checked[i] = (checked[edgeN] + 1) % 2;
			DFS(i);
		}
		else if (checked[i] == checked[edgeN]) {
			// �̺� �׷��� �Ұ�
			flag = false;
			return;
		}
	}

}


int main() {
	int t;
	cin >> t;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	for (int i = 0;i < t;i++) {
		int N, E;
		cin >> N >> E;

		edge.resize(N + 1);
		visited.resize(N + 1, false);
		checked.resize(N + 1, 0);
		flag = true;

		for (int j = 0;j < E;j++) {
			int a, b;
			cin >> a >> b;
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		// �־��� �׷����� �ϳ��� ����ȴٴ� ������ �����Ƿ� ��� ��忡�� ����
		for (int j = 1;j <= N;j++) {
			DFS(j);
			if (!flag) {
				break;
			}
		}
		if (flag) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}

		for (int j = 0;j <= N;j++) {
			edge[j].clear();
			visited[j] = false;
			checked[j] = 0;
		}



	}




}