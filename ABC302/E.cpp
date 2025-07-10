#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

int main() {
    ll N, Q;
    cin >> N >> Q;
    ll count = N;

    vector<set<int>> graph(N); 
    rep(i, Q){
        int query;
        cin >> query;
        if (query == 1){
            ll u, v;
            cin >> u >> v;
            if (graph[u-1].empty()) count--;
            if (graph[v-1].empty()) count--;
            graph[u-1].insert(v);
            graph[v-1].insert(u);
        } else if (query == 2){
            ll v;
            cin >> v;
            if (!graph[v-1].empty()) count++;
            for (const auto& elem : graph[v-1]){
                if(graph[elem-1].size() == 1) count++;
                graph[elem-1].erase(v);
            }
            graph[v-1].clear();
        }
        cout << count << endl;
    }

    return 0;
}