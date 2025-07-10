#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    long sum = 0;
    for (int i = 0; i < N; ++i){
        cin >> A[i];
        sum += A[i];
    }
    long long ans = 0;
    for (int i = 0; i < N; ++i){
        sum -= A[i];
        ans += A[i] * sum;
    }
    cout << ans << endl;
}