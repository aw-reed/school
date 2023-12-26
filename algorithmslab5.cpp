#include <iostream>
#include <vector>

using namespace std;

void radixSort(vector<vector<int>>& vectors){
    const int nums = vectors.size();
    const int vectorSize = 10;

    for (int digit = vectorSize - 1; digit >= 0; digit--){
        vector<vector<int>> buckets[4];

        for (int i = 0; i < nums; i++){
            int currentDigit = vectors[i][digit];
            buckets[currentDigit].push_back(vectors[i]);
        }

        vectors.clear();
        for (int i = 0; i < 4; i++){
            vectors.insert(vectors.end(), buckets[i].begin(), buckets[i].end());
        }
    }
}

int main(){
    int nums;
    cin >> nums;

    vector<vector<int>> vectors(nums, vector<int>(10));

    for (int i = 0; i < nums; i++){
        for (int j = 0; j < 10; j++){
            cin >> vectors[i][j];
        }
    }

    radixSort(vectors);

    for (int i = 0; i < nums; i++){
        for (int j = 0; j < 10; j++){
            cout << vectors[i][j];
            if (j < 10) cout << ";";
        }
        if (i < 4){
            cout << endl;
        }
    }

    return 0;
}
