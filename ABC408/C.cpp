#include <iostream>
#include <climits>

using namespace std;
int main() {
    int N, M;
    cin >> N >> M;

    int walls[N] = {0};
    for (int i = 0; i < M; i++) {
        int L, R;
        cin >> L >> R;

        if (L > R) swap(L, R);
        walls[L - 1]++;
        if (R < N) walls[R]--;
    }
    int min = INT_MAX;
    for (int i = 0; i < N; i++) {
        if (i > 0) walls[i] += walls[i - 1];
        if (walls[i] < min) min = walls[i];
    }
    cout << min << endl;
}
