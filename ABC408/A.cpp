#include <iostream>
using namespace std;

int main(){
    int N, S;
    cin >> N >> S;

    double pre_T = 0.0;
    for (int i = 0; i < N; i++) {
        int T;
        cin >> T;
        if (pre_T + S + 0.5 > T) {
            pre_T = T;
        } else {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}