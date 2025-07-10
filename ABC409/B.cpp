#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 100; i >= 0; --i) {
        int count = 0;
        for (int j = 0; j < N; ++j) {
            if (A[j] >= i) {
                count++;
            }
        }
        if (count >= i) {
            cout << i << endl;
            return 0;
        }
    }
}