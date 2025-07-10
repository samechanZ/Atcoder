#include <iostream>
#include <string>

using namespace std;

int main(){
    string T, U;
    cin >> T >> U;
    bool flag = false;

    for (int i = 0; i < (T.size()-U.size()) + 1; ++i) {
        for (int j = 0; j < U.size(); ++j) {
            if (T[j+i] == '?') {
                continue;
            }
            if (T[j+i] != U[j]) {
                flag = true;
                break;
            }
        }
        if (flag) {
            flag = false;
            continue;
        } else {
            cout << "Yes" << endl;
            exit(0);
        }
    }
    cout << "No" << endl;
}