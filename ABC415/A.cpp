#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

int main() {
    int N, X;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    cin >> X;
    rep(i, N){
        if (A[i] == X) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}