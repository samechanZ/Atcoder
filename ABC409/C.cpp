#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, L;
    cin >> N >> L;
    if (L % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    vector<vector<int>> A(L);
    int sum_d = 0;
    for (int i = 0; i < N; ++i){
        int d = 0;
        if (i != N - 1) {
            cin >> d;
        }
        A[sum_d].push_back(i + 1);
        sum_d += d;
        sum_d %= L;
    }
    vector<long long> vertex(3);
    long long count = 0;
    for (int i = 0; i < L/3; ++i){
        vertex[0] = A[i].size();
        vertex[1] = A[i + (L / 3)].size();
        vertex[2] = A[i + 2 * (L / 3)].size();
        if (vertex[0] == 0 || vertex[1] == 0 || vertex[2] == 0) continue;
        count += vertex[0] * vertex[1] * vertex[2];
    }
    cout << count << endl;
}