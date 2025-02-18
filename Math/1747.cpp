#include<iostream>
#include<cmath>

// ������ ���Ǳ�� �о����.
// N�� ������ ( 1~ 10,000,000) ������
// �������� �䱸�ϴ� ���� N���� ū �Ҽ� �̸鼭 �縰��Ҽ��� ���϶�� �Ͽ���

using namespace std;

bool isFelindrom(int inputNum) {
	int j = inputNum;
	int jaritsu = 0;
	while (j > 0) {
		j /= 10;
		jaritsu++;
	}
	int a = inputNum;
	int b = 0;
	int c = 10;
	while (true) {
		b += a % c;
		if (jaritsu == 1) break;
		b *= 10;
		a /= 10;

		jaritsu--;
	}

	if (inputNum == b) {
		return true;
	}
	else {
		return false;
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	bool V[10000001] = { true };
	int A;
	cin >> A;

	for (int j = 1;j <= 10000001;j++) {
		V[j] = true;
	}

	V[1] = false;
	for (int i = 2;i <= sqrt(10000001);i++) {
		if (!V[i]) continue;
		for (int j = i + i;j <= 10000001;j += i) {
			V[j] = false;
		}
	}



	for (int a = A;a <= 10000000;a++) {
		if (!V[a]) continue;
		if (isFelindrom(a)) {
			cout << a;
			break;
		}

	}

	return 0;




}