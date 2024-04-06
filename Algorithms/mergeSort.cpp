#include <iostream>
#include <vector>

using namespace std;

void maxHeapify(vector<int>& a, int n, int i) {
    int largest = i;
    int left = i << 1;
    int right = left + 1;

    if (left <= n && a[left] > a[largest]) {
        largest = left;
    }
    if (right <= n && a[right] > a[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(a[i], a[largest]);
        maxHeapify(a, n, largest);
    }
}

void buildMaxHeap(vector<int>& a, int n) {
    for (int i = n / 2; i >= 1; i--) {
        maxHeapify(a, n, i);
    }
}

void heapSort(vector<int>& a, int n) {
    buildMaxHeap(a, n);

    for (int i = n; i >= 2; i--) {
        swap(a[1], a[i]);
        maxHeapify(a, i - 1, 1);
    }
}

int main() {
    vector<int> arr = {-1, 12, 11, 13, 5, 6, 7}; // 下标 0 的位置闲置，不使用
    int n = arr.size() - 1; // 数组中元素的数量
    heapSort(arr, n);
    
    cout << "Sorted array is \n";
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}