#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, M, Q;
    cin >> N >> M >> Q;
    int dataset[N][M+1] = {0};
    int output[Q] = {0};

    for (int i = 0; i < Q; ++i) {
        int command, user, item;
        cin >> command;
        if (command == 1) {
            cin >> user >> item;
            dataset[user-1][item-1] = 1;
        } else if (command == 2) {
            cin >> user;
            dataset[user-1][M] = 1;
        } else if (command == 3) {
            cin >> user >> item;
            if (dataset[user-1][item-1] == 1) {
                output[i] = 1;
            } else if (dataset[user-1][M] == 1) {
                output[i] = 1;
            } else {
                output[i] = 2;
            }
        }
            
    }

    for (int i = 0; i < Q; ++i) {
        if (output[i] == 1) {
            cout << "Yes" << endl;
        } else if (output[i] == 2) {
            cout << "No" << endl;
        }
    }
}