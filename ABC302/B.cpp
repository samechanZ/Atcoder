#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    rep(i, H){
        rep(j, W){
            if (S[i][j] == 's') {
                string snake = "snuke";
                for (int k = -1; k < 2; k++){
                    for (int l = -1; l <2; l++){
                        if (k == 0 && l == 0) continue;
                        bool found = true;
                        rep(n, 4) {
                            if (0 > i + (k * (n + 1)) || i + (k * (n + 1)) >= H || 0 > j + (l * (n + 1)) || j + (l * (n + 1)) >= W) {
                                found = false;
                                break;
                            }
                            if (S[i + (k * (n + 1))][j + (l * (n + 1))] != snake[n+1]){
                                found = false;
                                break;
                            }
                        }
                        if (found) {
                            cout << i + 1 << " " << j + 1 << endl;
                            rep(n, 4) {
                                cout << i + (k * (n + 1)) + 1 << " " << j + (l * (n + 1)) + 1<< endl;
                            }
                            return 0;
                        }
                    }
                }
            }
        }
    }

    return 0;
}