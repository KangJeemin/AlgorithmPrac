#include<iostream>
#include<cmath>

// �����佺ü�� �Ҽ� ���ϱ�
// temp *= i �ڵ尡 if �� �ȿ� ��ġ�� ��� �ð��ʰ� �߻�

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	bool V[10000001] = { true };
	long A, B;
	cin >> A >> B;

	for (int j = 1;j <= 10000000;j++) {
		V[j] = true;
	}

	V[1] = false;
	for (int i = 2;i <= sqrt(10000000);i++) {
		if (!V[i]) continue;
		for (int j = i + i;j <= 10000000;j += i) {
			V[j] = false;
		}
	}
	long ans = 0;

	for (long i = 2;i <= 10000000;i++) {
		if (V[i]) {
			long temp = i;


			while ((double)i <= (double)B / (double)temp) {
				if ((double)i >= (double)A / (double)temp) {
					ans++;

				}
				temp *= i;
			}
		}



	}

	cout << ans;


}