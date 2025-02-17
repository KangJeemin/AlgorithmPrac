#include<iostream>
#include<vector>
#include<cmath> 
// sqrt �Լ� ����ϱ� ���� ���
using namespace std;

// DFS�� �̿��� ���� 1���� �̾� ������ N�ڸ������� Ž���Ѵ�.
// �̶� ¦���� ��� Ž������ �ʴ´�.
// ù°�ڸ��� 2���� 9���� Ž���Ѵ�
// �ι�°�ڸ����� 1���� 9���� Ž���Ѵ�.
// N�ڸ����� �����ߴٸ� �ش���� �Ҽ����� �ƴ��� �ݺ��Ѵ�.



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