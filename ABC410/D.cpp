#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<Edge>> graph(N);
    for (int i = 0; i < M; ++i) {
        int A, B, W;
        cin >> A >> B >> W;

        graph[A - 1].push_back(Edge(B - 1, W));
    }
}