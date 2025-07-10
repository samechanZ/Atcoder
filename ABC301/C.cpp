#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isAtcoder(const int i){
    if (i == 'a' - 'a' || i == 't' - 'a' || i == 'c' - 'a' ||
        i == 'o' - 'a' || i == 'd' - 'a' || i == 'e' - 'a' || i == 'r' - 'a') {
        return true;
    }
    return false;
}

int main(){
    string S, T;
    cin >> S >> T;
    vector<int> countS(27, 0), countT(27, 0);
    for (int i = 0; i < S.size(); ++i) {
        if (S[i]  == '@') countS[26]++;
        else countS[S[i]-'a']++;
        if (T[i]  == '@') countT[26]++;
        else countT[T[i]-'a']++;
    }
    bool canWin = true;
    for (int i = 0; i < 26; ++i) {
        if (countS[i] < countT[i]) {
            if (isAtcoder(i)) {
                countS[26] -= countT[i] - countS[i];
            }else {
                canWin = false;
                break;
            }
        } else if (countS[i] > countT[i]) {
            if (isAtcoder(i)) {
                countT[26] -= countS[i] - countT[i];
            } else {
                canWin = false;
                break;
            }
        }
    }
    if (countS[26] < 0 || countT[26] < 0 || !canWin) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}