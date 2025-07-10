#include <iostream>
#include <vector>

using namespace std;

int main(){
    int Q;
    cin >> Q;
    int type;
    vector<int> queue;
    for (int i = 0; i < Q; i++){
        cin >> type;
        if (type == 1){
            int x;
            cin >> x;
            queue.push_back(x);
        } else if (type == 2){
            cout << queue[0] << endl;
            queue.erase(queue.begin());
        }
    }
}