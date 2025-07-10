#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int T;
    cin >> T;

    vector<string> results(T);
    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;
        string S;
        cin >> S;

        for (int i = 0; i < N; ++i) {
            if (S[i] <= S[i+1]){
                continue;
            } else {
                for (int j = i + 1; j < N; ++j) {
                    if (S[j] < S[i]) {
                        swap(S[i], S[j]);
                        break;
                    }
                }
                break;
            }
        }
        results[t] = S;
    }
    for (const string& result : results) {
        cout << result << endl;
    }
}