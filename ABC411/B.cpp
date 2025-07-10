#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> D(N);
    for (int i = 0; i < N-1; ++i) {
        cin >> D[i];
    }
    vector<int> dif(N, 0);
    for (int i = 0; i < N - 1; ++i) {
        if (i == 0) {
            dif[i] = D[i];
        } else {
            dif[i] = dif[i-1] + D[i];
        }
        cout << dif[i] << " ";
    }
    cout << endl;
    for (int i = N-2; i >= 0; --i) {
        for (int j = 0; j < i ; ++j) {
            if (j == 0) {
                cout << dif[j+1] - dif[j] << " ";
                dif[j] = dif[j+1] - dif[j];
            } else {
                cout << dif[j+1] - dif[j] + dif[j-1] << " ";
                dif[j] = dif[j+1] - dif[j] + dif[j-1];
            } 
        }
        cout << endl;
        dif.erase(dif.end() - 1);
    }
}