#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

void dfs(const vector<vector<int>>& check, vector<bool> &explored, int idx){
    rep(i, check[idx].size()){
        if(explored[check[idx][i]]) continue;
        explored[check[idx][i]] = true;
        dfs(check, explored, check[idx][i]);
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    vector<vector<int>> check(N);
    vector<bool> explored(N, false);
    vector<int> route(N);
    rep(i, N) cin >> S[i];
    rep(i, N){
        rep(j, N){
            if (i <= j) continue;
            int count = 0;
            rep(k, M){
                if(S[i][k] == S[j][k]){
                    count++;
                }
            }
            if (count == M-1) {
                check[i].push_back(j);
                check[j].push_back(i);
            }
        }
    }
    dfs(check, explored, 0);
    rep(i, N){
        if(!explored[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}