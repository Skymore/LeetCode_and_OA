#include<string>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:

// 自定义比较函数
    bool customCompare(const string& a, const string& b, const unordered_map<char, int>& orderMap) {
        int lenA = a.length(), lenB = b.length();
        for (int i = 0; i < min(lenA, lenB); ++i) {
            if (a[i] != b[i]) {
                return orderMap.at(a[i]) < orderMap.at(b[i]);
            }
        }
        return lenA < lenB; // 如果一个字符串是另一个字符串的前缀，则较短的字符串更小
    }

    void sortByCustomOrder(const string& order, vector<string>& strs) {
        unordered_map<char, int> orderMap;

        // 建立每个字符在自定义顺序中的索引映射
        for (int i = 0; i < order.length(); ++i) {
            orderMap[order[i]] = i;
        }

        // 使用自定义比较函数进行排序
        sort(strs.begin(), strs.end(), [&orderMap, this](const string& a, const string& b) -> bool {
            return customCompare(a, b, orderMap);
        });
    }
};

int main()
{
    std::vector<std::string> strs = {"fd", "fbk", "mc"};
    std::string order = "mnbvcxzlkjhgfdsapoiuytrewq";
    Solution S;
    S.sortByCustomOrder(order, strs);

    // 打印排序后的字符串数组
    for (const auto& str : strs) {
        std::cout << str << " ";
    }
    return 0;
}