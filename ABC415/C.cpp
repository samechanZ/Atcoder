#include <iostream>
#include <vector>
#include <string>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

int main() {
    int T;
    cin >> T;
    vector<string> results;
    while (T--){
        int N;
        string S;
        cin >> N >> S;
        int total = 1 << N;
        vector<bool> visited(total, false);
        queue<int> que;
        que.push(0);
        visited[0] = true;

        while (!que.empty()) {
            int now = que.front();
            que.pop();
            for (int i = 0; i < N; ++i) {
                if ((now >> i) & 1) continue;
                int next = now | (1 << i);
                if (!visited[next] && S[next-1] != '1') {
                    visited[next] = true;
                    que.push(next);
                }
            }
        }
         if (visited[total - 1]) {
            results.push_back("Yes");
        } else {
            results.push_back("No");
        }
    }

    for (const string& result : results) {
        cout << result << endl;
    }

    return 0;
}
