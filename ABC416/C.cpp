#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

int main() {
    int N, K, X;
    cin >> N >> K >> X;
    vector<string> S(N);
    rep(i, N) cin >> S[i];
    vector<string> allString;
    long long total = 1;
    for(int i = 0; i < K; ++i) total *= N;

    for (long long i = 0; i < total; ++i) {
        string current_str = "";
        long long temp_idx = i;
        rep(j, K) {
            int idx = temp_idx % N;
            current_str = S[idx] + current_str;
            temp_idx /= N;
        }
        allString.push_back(current_str);
    }
    sort(allString.begin(), allString.end());
    cout << allString[X - 1] << endl;

    return 0;
}