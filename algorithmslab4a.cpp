#include <iostream>

using namespace std;

// heapifys the array
void heapify(int A[], int n, int i){
    int largest = i; //largest is the root num
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    // checks if left child of root exists and if it's greater than given root
    if (l < n && A[i] < A[l]) {
        largest = l;
    }
    
    // checks if right child of root exists and if it's greater than largest
    if (r < n && A[largest] < A[r]){
        largest = r;
    }

    if (largest != i){
        swap(A[i], A[largest]);

        heapify(A, n, largest);
    }
}

void heapSort(int A[], int n){
    // Builds maxheap
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(A, n, i);
    }
    // gets elements in the heap 1 by 1
    for (int i = n - 1; i >= 0; i--){
        swap(A[0], A[i]);
        heapify(A, i, 0);
    }
}

void print(int A[], int n){
    for (int i = 0; i < n; i++){
        cout << A[i] << ";";
    }
    cout << endl;
}

int main(){
    int arraySize;
    cin >> arraySize;
    int A[arraySize];

    for (int i = 0; i < arraySize; i++){
        cin >> A[i];
    }

    heapSort(A, arraySize);

    print(A, arraySize);

    return 0;
}
