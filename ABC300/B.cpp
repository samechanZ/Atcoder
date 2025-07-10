#include <iostream>
#include <vector>

using namespace std;

int main(){
    int H, W;
    cin >> H >> W;

    vector<string> A(H);
    vector<string> B(H);

    for (int i = 0; i < H; i++){
        cin >> A[i];
    }
    for (int i = 0; i < H; i++){
        cin >> B[i];
    }

    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            bool correspond = true;
            for (int k = 0; k < H; k++){
                for (int l = 0; l < W; l++){
                    if (A[(k+i)%H][(l+j)%W] != B[k][l]){
                        correspond = false;
                        break;
                    }
                }
                if (!correspond) break;
            }
            if (correspond) {
                cout << "Yes" << endl;
                exit(0);
            }
        }
    }
    cout << "No" << endl;
}