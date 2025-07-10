#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    int temp = 0;
    int Sum = 0;

    for (int i = 0; i < N; ++i) {
        cin >> temp;
        if (i%2 == 0) {
            Sum += temp;
        }
    }
    cout << Sum << endl;
}