#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N);
    vector<int> count(N);
    rep(i, M){
        int A, B;
        cin >> A >> B;
        graph[A-1].push_back(B);
        graph[B-1].push_back(A);
    }
    int opcount = 0;
    rep(i, N){
        while (graph[i].size() != 2 && graph[i].size() < 2){
            int min = 8, minidx = 0;
            rep(j, N){
                if (i == j) continue;
                if (min > graph[j].size()){
                    rep(m, graph[j].size()) if (graph[j][m] == i+1) continue;
                    min = graph[j].size();
                    minidx = j;
                }
            }
            graph[minidx].push_back(i+1);
            graph[i].push_back(minidx+1);
            opcount++;
            cout << "add" << endl;
        }
        while(graph[i].size() != 2 && graph[i].size() > 2){
            int max = 0, maxidx = 0;
            rep(j, graph[i].size()){
                if (graph[graph[i][j]-1].size() > max){
                    max = graph[graph[i][j]-1].size();
                    maxidx = graph[i][j]-1;
                }
            }
            graph[i].erase(graph[i].begin() + maxidx);
            graph[maxidx].erase(graph[maxidx].begin() + i);
            opcount++;
            cout << "delete" << endl;
        }
        bool isOK = true;
        rep(j, N) if (graph[j].size() != 2) isOK = false;
        if (!isOK && i == N-1) i = 0;
    }
    cout << opcount << endl;

    return 0;
}