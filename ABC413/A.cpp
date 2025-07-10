#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int sum = 0;
    rep(i, N){
        int A;
        cin >> A;
        sum += A;
    }
    if (sum <= M) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}