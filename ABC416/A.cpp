#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

int main() {
    int N, L, R;
    string S;
    cin >> N >> L >> R >> S;
    for (int i = L-1; i < R; ++i) {
        if (S[i] == 'x') {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
