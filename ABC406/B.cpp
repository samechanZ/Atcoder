#include <iostream>
#include <vector>
using namespace std;

int getDigit(long long n){
    return to_string(n).length();
}

int main(){
    int N, K;
    cin >> N >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    long long ans = 1;
    for (int i = 0; i < N; ++i){
        ans *= A[i];
        if (i == N-1) break;
        int ketaagari = 0;
        if ((to_string(ans)[0] - '0') * (to_string(A[i+1])[0]-'0') > 9){
            ketaagari = 1;
        }
        if (getDigit(ans) + getDigit(A[i+1]) - 1 + ketaagari > K){
            ans = 1;
            i++;
        }
        if (getDigit(ans) > K || ans < 0 || ans > 1e18){
            ans = 1;
        }
    }
    cout << ans << endl;
}