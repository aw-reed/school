#include <iostream>
#include <vector>
#include <tuple>
#include <climits>

using namespace std;

tuple<int, int, int> findMaxCrossingSubArray(vector<int>& A, int low, int mid, int high){
    int left_sum = INT_MIN; // negative infinity
    int sum = 0;
    int max_left, max_right;

    for (int i = mid; i >= low; i--){
        sum = sum + A[i];
        if (sum > left_sum){
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = INT_MIN; // negative infinity
    sum = 0;

    for (int j = mid + 1; j <= high; j++){
        sum = sum + A[j];
        if (sum > right_sum){
            right_sum = sum;
            max_right = j;
        }
    }

    return make_tuple(max_left, max_right, left_sum + right_sum);
}

tuple<int, int, int> findMaximumSubArray(vector<int>& A, int low, int high){
    if (high == low){
        return make_tuple(low, high, A[low]);
    } else {
        int mid = (low + high) / 2;
        auto left_sum = findMaximumSubArray(A, low, mid);
        auto right_sum = findMaximumSubArray(A, mid + 1, high);
        auto cross_sum = findMaxCrossingSubArray(A, low, mid, high);

        if (get<2>(left_sum) >= get<2>(right_sum) && get<2>(left_sum) >= get<2>(cross_sum)){
            return left_sum;
        } else if (get<2>(right_sum) >= get<2>(left_sum) && get<2>(right_sum) >= get<2>(cross_sum)){
            return right_sum;
        } else {
            return cross_sum;
        }
    }
}

int main(){
    int arraySize;
    cin >> arraySize;
    vector<int> A(arraySize);

    for (int i = 0; i < arraySize; i++){
        cin >> A[i];
    }

    auto result = findMaximumSubArray(A, 0, arraySize - 1);
    int max_sum = get<2>(result);

    cout << max_sum << endl;

    return 0;
}
