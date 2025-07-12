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
    vector<ll> X(N), D(N-1);
    rep(i, N) cin >> X[i];
    sort(X.begin(), X.end());
    rep(i, N-1) D[i] = X[i+1] - X[i];
    sort(D.begin(), D.end());
    ll result = 0;
    rep(i, N-M) result += D[i];
    cout << result << endl;
}