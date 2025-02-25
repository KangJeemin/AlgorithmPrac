#include<iostream>

using namespace std;

static int n;
static int tree[26][2];
void preOrder(int now);
void inOrder(int now);
void postOrder(int now);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0;i < n;i++) {
        char nodeC, left, right;
        cin >> nodeC >> left >> right;
        int node = nodeC - 'A';
        if (left == '.') {
            tree[node][0] = -1;
        }
        else {
            tree[node][0] = left - 'A';
        }
        if (right == '.') {
            tree[node][1] = -1;
        }
        else {
            tree[node][1] = right - 'A';
        }
    }

    preOrder(0);
    cout << '\n';
    inOrder(0);
    cout << '\n';
    postOrder(0);
    cout << '\n';


    return 0;
}

void preOrder(int now) {
    if (now == -1) {
        return;
    }
    cout << static_cast<char>(now + 'A');
    preOrder(tree[now][0]);
    preOrder(tree[now][1]);
}

void inOrder(int now) {
    if (now == -1) {
        return;
    }
    inOrder(tree[now][0]);
    cout << static_cast<char>(now + 'A');
    inOrder(tree[now][1]);

}
void postOrder(int now) {
    if (now == -1) {
        return;
    }
    postOrder(tree[now][0]);
    postOrder(tree[now][1]);
    cout << static_cast<char>(now + 'A');

}

