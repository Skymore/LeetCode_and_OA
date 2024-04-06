#include <iostream>
#include <vector>

using namespace std;

void quicksort(int ll, int rr, vector<int> &a) {
    if (ll >= rr) return;
    int i = ll;
    int j = rr;
    int mid = ll + (ll + rr) >> 1;
    swap(a[ll], a[mid]);

    int pivot = a[ll];
    while (i < j) {
        while (i < j && a[j] >= pivot) j--;
        while (i < j && a[i] <= pivot) i++;
        if (i < j) swap(a[i], a[j]);
    }
    swap(a[ll], a[i]);
    quicksort(ll, i-1, a);
    quicksort(i+1, rr, a);
}

vector<int> sortArray(vector<int> &nums) {
    quicksort(0, nums.size() - 1, nums);
    return nums;
}

int main() {

}