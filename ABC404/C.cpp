#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> graph[N];
    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        graph[A-1].push_back(B-1);
        graph[B-1].push_back(A-1);
    }
    for (int i = 0; i < N; ++i) {
        if (graph[i].size() != 2) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}