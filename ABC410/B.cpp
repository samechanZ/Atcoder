#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> X(Q);
    vector<int> B(Q);
    vector<int> Box(N);
    
    for (int i = 0; i < Q; ++i) {
        cin >> X[i];
        if (X[i] >= 1){
            B[i] = X[i];
            Box[X[i]-1]++;
        } else {
            int min = 1000;
            int min_index = -1;
            for (int j = 0; j < N; ++j) {
                if (Box[j] < min) {
                    min = Box[j];
                    min_index = j;
                }
            }
            B[i] = min_index + 1;
            Box[min_index]++;
        }
    }

    for (int i = 0; i < Q; ++i) {
        cout << B[i];
        if (i < Q - 1) {
            cout << " ";
        }
    }
}