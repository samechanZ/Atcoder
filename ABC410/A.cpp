#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    int K;
    cin >> K;
    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] >= K) {
            count++;
        }
    }
    cout << count << endl;
}