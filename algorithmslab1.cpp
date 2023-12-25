#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& A){
    int length = A.size();

    for (int j = 1; j < length; j++){
        int key = A[j];
        int i = j - 1;

        while (i >= 0 && A[i] > key){
            A[i + 1] = A[i];
            i--;
        }

        A[i + 1] = key;
    
    for (int h = 0; h <= j; h++){
        cout << A[h];
        if (h < j){
            cout << ";";
        }
    }
    cout << ";" << endl;
    }
}

int main(){
    int arraySize;
    cin >> arraySize;

    vector<int> A(arraySize);

    for (int i = 0; i < arraySize; i++){
        cin >> A[i];
    }

    insertionSort(A);

    return 0;
}
