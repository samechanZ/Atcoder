#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

int main() {
    int N;
    cin >> N;
    string S = "";
    bool flag = false;
    rep(i, N){
        string c;
        ll l;
        cin >> c >> l;
        if (size(S) + l > 100) {
            flag = true;
        }
        rep(j, l) {
            if (flag) break;
            S += c;
        }
    }
    if (flag) {
        cout << "Too Long" << endl;
        return 0;
    }
    cout << S << endl;
    return 0;
}