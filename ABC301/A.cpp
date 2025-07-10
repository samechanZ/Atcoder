#include <iostream>
#include <string>

using namespace std;

int main(){
    int N;
    string S;
    cin >> N >> S;
    int T = 0;
    int A = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] == 'T') {
            T++;
            if (T == N / 2) {
                cout << "T" << endl;
                exit(0);
            }
        } else {
            A++;
            if (A == N / 2) {
                cout << "A" << endl;
                exit(0);
            }
        }
    }
    if (T > A) {
        cout << "T" << endl;
    } else if (A > T) {
        cout << "A" << endl;
    } else {
        int i = N - 1;
        while (i >= 0 && S[i] == 'T') {
            i--;
        }
        cout << S[i] << endl;
    }
}