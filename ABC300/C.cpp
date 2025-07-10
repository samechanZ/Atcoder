#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    vector<string> grid(H);
    for (int i = 0; i < H; ++i) {
        cin >> grid[i];
    }

    int N = (H < W) ? H : W;
    vector<int> S(N);

    for (int i = 1; i < H-1; ++i) {
        for (int j = 1; j < W-1; ++j) {
            if (grid[i][j] == '#') {
                int size = 0;
                if (grid[i-1][j-1] == '#' && grid[i+1][j+1] == '#' && grid[i+1][j-1] == '#' && grid[i-1][j+1] == '#') {
                    while (true) {
                        if (i - size-1 < 0) break;
                        if (grid[i-size-1][j-size-1] == '#') {
                            size++;
                        } else {
                            break;
                        }
                    }
                    S[size-1]++;
                }
            }
        }
    }
    
    for (int i = 0; i < N; ++i) {
        cout << S[i];
        if ( i != S.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}