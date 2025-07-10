#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    for (int i = 0; i < N; i++) {
        int temp = A[i];
        for (int j = i + 1; j < N; j++) {
            if (A[j] == temp) {
                A.erase(A.begin() + j);
                N--;
                j--;
            } else {
                break;
            }
        }
    }
    cout << N << endl;
    for (int i = 0; i < A.size(); i++) {
        cout << A[i];
        if (i < A.size() - 1) cout << " ";
    }
}