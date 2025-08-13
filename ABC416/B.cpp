#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

int main() {
    string S, T;
    cin >> S;
    T = S;
    int temp = 0;
    bool foundSharp = false, putFirst = false;
    rep(i, S.size()) {
        char c = S[i];
        if (c == '#' && putFirst){
            foundSharp = true;
        } else if (c == '.' && !putFirst){
            putFirst = true;
            temp = i;
        } else if (c == '.' && foundSharp) {
            S[temp] = 'o';
            S[i] = 'o';
            foundSharp = false;
        }
    }
    bool alldot = true;
    rep(i, T.size()) {
        if (T[i] != '.') {
            alldot = false;
        }
    }
    if (alldot) {
        S[0] = 'o';
        cout << S << endl;
        return 0;
    }

    cout << S << endl;
    return 0;
}