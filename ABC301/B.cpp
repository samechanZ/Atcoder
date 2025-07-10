#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    for (int i = 0; i < A.size(); ++i) {
        if (i == A.size() - 1) break;
        if (A[i+1] - A[i] > 1){
            vector<int> intertA(A[i+1] - A[i] - 1);
            for (int j = 0; j < intertA.size(); ++j) {
                intertA[j] = A[i] + j + 1;
            }
            A.insert(A.begin() + i + 1, intertA.begin(), intertA.end());
            i += intertA.size();
        } else if (A[i+1] - A[i] < 1){
            vector<int> intertA(A[i] - A[i+1] - 1);
            for (int j = 0; j < intertA.size(); ++j) {
                intertA[j] = A[i] - j - 1;
            }
            A.insert(A.begin() + i + 1, intertA.begin(), intertA.end());
            i += intertA.size();
        }
    }
    for (int i = 0; i < A.size(); ++i) {
        cout << A[i];
        if (i != A.size() - 1) {
            cout << " ";
        }
    }
}