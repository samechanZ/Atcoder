#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> graph(N);
    vector<int> dim(N, 0);
    vector<bool> check(N, false);

    rep(i, N-1){
        int u, v;
        cin >> u >> v;
        dim[u-1]++;
        dim[v-1]++;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
    queue<int> que;
    rep(i, N) if(dim[i] == 1) que.push(i);
    while(!que.empty()){
        int mid;
        for(int idx : graph[que.front()]) if(!check[idx]) mid = idx;
        if(check[mid]){
            que.pop();
            continue;
        }
        check[mid] = true;
        for(int idx : graph[mid]){
            check[idx] = true;
            if(graph[idx].size() != 1){
                for(int nidx : graph[idx]){
                    if(nidx == mid || check[nidx]) continue;
                    dim[idx]--;
                    dim[nidx]--;
                    if(dim[nidx] == 1) que.push(nidx);
                }
            }
        }
        que.pop();
    }
    vector<int> ans(N, 0);
    rep(i, N) if (dim[i] != 0) ans[dim[i]-1]++;
    rep(i, N) {
        if (ans[i] > 0 && i != 0){
            rep(j, ans[i]) cout << i+1 << ' '; 
        }
    }
    cout << endl;

    return 0;
}