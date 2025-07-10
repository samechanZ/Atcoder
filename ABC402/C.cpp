#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> recipe;
    for (int i = 0; i < M; i++){
        int x;
        cin >> x;
        vector<int> Ingredient;
        for (int j = 0; j < x; j++){
            int y;
            cin >> y;
            Ingredient.push_back(y);
        }
        sort(Ingredient.begin(), Ingredient.end());
        recipe.push_back(Ingredient);
    }
    int count = 0;
    vector<int> hatedIngredient;
    for (int i = 0; i < N; i++){
        int x;
        cin >> x;
        hatedIngredient.push_back(x);
    }
    for (int k = 0; k < N; k++){
        for (int i = 0; i < recipe.size(); i++){
            for (int j = 0; j < recipe[i].size(); j++){
                if (recipe[i][j] > hatedIngredient[k]){
                    break;
                }
                if (recipe[i][j] == hatedIngredient[k]){
                    recipe[i].erase(recipe[i].begin() + j);
                    if (recipe[i].size() == 0){
                        recipe.erase(recipe.begin() + i);
                        i--;
                        count++;
                    }
                    break;
                }
            }
        }
        cout << count  << endl;
    }
}