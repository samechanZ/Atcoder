#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int N, Q;
    cin >> N >> Q;
    vector<int> line(N, 0);
    vector<int> A(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> A[i];
    }

    int groupCount = 0;
    for (int i = 0; i < Q; ++i) {
        int x = A[i] - 1;
        if (line[x] == 0) {
            if (x == 0 && line[x + 1] == 0) {
             groupCount++;
            } else if (x == N - 1 && line[x - 1] == 0) {
             groupCount++;
            } else if (line[x - 1] == 0 && line[x + 1] == 0) {
             groupCount++;
            } else if (line[x - 1] == 1 && line[x + 1] == 1) {
             groupCount--;
            }
            line[x] = 1;
        } else {
            if (x == 0 && line[x + 1] == 0) {
             groupCount--;
            } else if (x == N - 1 && line[x - 1] == 0) {
             groupCount--;
            } else if (line[x - 1] == 0 && line[x + 1] == 0) {
             groupCount--;
            } else if (line[x - 1] == 1 && line[x + 1] == 1) {
             groupCount++;
            }
            line[x] = 0;
        }
        cout << groupCount << endl;
    }
}