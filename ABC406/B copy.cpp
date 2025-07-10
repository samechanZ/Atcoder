#include <iostream>
#include <climits>
using namespace std;


int main(){
    int N, K;
    cin >> N >> K;
    long long A;
    long long ans = 1;
    for (int i = 0; i < N; ++i){
        cin >> A;
        if (ans > LLONG_MAX / A) {
            ans = 1;
            continue;
        }
        ans *= A;
        if (ans > 1e18 || ans < 0 || to_string(ans).length() > K){
            ans = 1;
        }
    }
    cout << ans << endl;
}