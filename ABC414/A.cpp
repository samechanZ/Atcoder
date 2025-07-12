#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

int main() {
    int N, L , R, count = 0;
    cin >> N >> L >> R;
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        if (x <= L && y >= R) count++;
    }
    cout << count << endl;
    return 0;
}