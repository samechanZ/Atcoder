#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) A[i] = i+1;

    long long queryType;
    long long shift_count = 0;
    for(int i = 0; i < Q; ++i){
        cin >> queryType;
        if (queryType == 1){
            long long p, x;
            cin >> p >> x;
            p = (p + shift_count + N - 1) % N;
            A[p] = x;
        } else if (queryType == 2){
            long long p;
            cin >> p;
            p = (p + shift_count + N - 1) % N;
            cout << A[p] << endl;
        } else if (queryType == 3){
            long long k;
            cin >> k;
            shift_count = (shift_count + k) % N;
        }
    }
}