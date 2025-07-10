#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(M+N);
    rep(i, N){
        int A;
        cin >> A;
        rep(j, A){
            int S;
            cin >> S;
            graph[i].push_back(N + S-1);
            graph[N + S-1].push_back(i);
        }
    }

    vector<int> dist(M+N, -1);
    queue<int> que;
    dist[N] = 0;
    que.push(N);

    while(!que.empty()){
        int v = que.front();
        que.pop();

        for(int nv : graph[v]){
            if (dist[nv] != -1) continue;
            dist[nv] = dist[v] +1;
            que.push(nv);
        }
    }
    cout << (dist[N+M-1]-1)/2 << endl;

    return 0;
}