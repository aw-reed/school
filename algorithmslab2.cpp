#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right){
    int x = mid - left + 1;
    int y = right - mid;

    vector<int> L(x);
    vector<int> R(y);

    for (int i = 0; i < x; i++){
        L[i] = arr[left + i];
    }

    for (int j = 0; j < y; j++){
        R[j] = arr[mid + j + 1];
    }

    int i = 0, j = 0, k = left;

    while (i < x && j < y){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < x){
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < y){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right){
    if (left < right){
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge (arr, left, mid, right);
    }
}

int main(){
    int arraySize;
    cin >> arraySize;

    vector<int> array(arraySize);

    for (int i = 0; i < arraySize; i++){
        cin >> array[i];
    }

    mergeSort(array, 0 , array.size() - 1);

    for (int num : array){
        cout << num << ";";
    }

    cout << endl;

    return 0;
}
