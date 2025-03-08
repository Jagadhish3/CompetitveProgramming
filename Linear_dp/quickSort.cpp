#include <iostream>
using namespace std;

int partition(int arr[], int s, int e) {
    int pivot = arr[e]; // Select the last element as the pivot
    int i = s - 1; // Index of smaller element

    for (int j = s; j < e; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    // Place the pivot in its correct position
    swap(arr[i + 1], arr[e]);
    return i + 1;
}

void quicksort(int arr[], int s, int e) {
    if (s < e) {
        int p = partition(arr, s, e); // Partitioning index
        quicksort(arr, s, p - 1);    // Sort the left subarray
        quicksort(arr, p + 1, e);    // Sort the right subarray
    }
}

int main() {
    int a[5] = {2, 3, 6, 7, 1};
    quicksort(a, 0, 4); // Pass the correct range (0 to 4 for 5 elements)

    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
