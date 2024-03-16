/*
 * 给一个数组，和一个pivot
 * 数组里严格小于pivot的个数为count_less
 * 数组里严格大于pivot的个数为count_greater
 * if count_less > count_greater, return "less"
 * if count_less < count_greater, return "greater"
 * if count_less == count_greater, return "tie"
 */

#include <iostream>
#include <vector>

using namespace std;

string solution(vector<int> &nums, int pivot) {
    int count_less = 0, count_greater = 0;
    for (int num : nums) {
        if (num < pivot) {
            count_less++;
        } else if (num > pivot) {
            count_greater++;
        }
    }
    if (count_less > count_greater) return "less";
    if (count_less < count_greater) return "greater";
    return "tie";
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << solution(nums, 3) << endl;
    cout << "reference answer: tie" << endl;
    return 0;
}