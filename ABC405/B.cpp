#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    set<int> number;
    for (int i = 0; i < N; ++i){
        cin >> A[i];
        number.insert(A[i]);
        if (number.size() == M){
            cout << N - i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}