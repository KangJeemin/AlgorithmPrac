#include<iostream>
#include<vector>

using namespace std;

int N, M;

vector<bool> visited;
vector<vector<int>> line;

void init() {
	cin >> N >> M;
	visited.resize(N + 1, false);
	line.resize(N + 1);

	for (int i = 1;i <= M;i++) {
		int a, b;
		cin >> a >> b;
		line[a].push_back(b);
		line[b].push_back(a);
	}
}


void DFS(int edge) {
	vector<int> DFS;
	DFS.push_back(edge);

	while (!DFS.empty()) {
		int medge = DFS.back();
		DFS.pop_back();
		for (auto i : line[medge]) {
			if (visited[i]) continue;
			visited[i] = true;
			DFS.push_back(i);
		}
	}
}
int main() {
	int ans = 0;
	init();

	for (int i = 1;i <= N;i++) {
		if (!visited[i]) {
			ans++;
			DFS(i);
		}
	}
	cout << ans;
}