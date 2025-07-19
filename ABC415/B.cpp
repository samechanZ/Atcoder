#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    int first_pick = -1, second_pick = -1;
    rep(i, N){
        if (S[i] == '#' && first_pick == -1){
            first_pick = i + 1;
        } else if (S[i] == '#' && second_pick == -1) {
            second_pick = i + 1;
            cout << first_pick << "," << second_pick << endl;
            first_pick = -1, second_pick = -1;
        }
    }

    return 0;
}