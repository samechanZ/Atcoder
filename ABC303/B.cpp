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
    vector<vector<bool>> pair(N, vector<bool>(N, false));
    rep(i, M){
        rep(j, N){
            int a, ba;
            cin >> a;
            if (j == 0){
                ba = a;
                continue;
            }
            pair[a-1][ba-1] = true;
            pair[ba-1][a-1] = true;
            ba = a;
        }
    }
    int count = 0;
    rep(i, N){
        rep(j, N){
            if (i == j) continue;
            if (!pair[i][j]) count++;
        }
    }
    cout << count/2 << endl;

    return 0;
}