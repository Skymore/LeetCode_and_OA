//
// Created by 陶睿 on 10/25/23.
//
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>


using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people) {
        map<int, int> diff;
        diff[0] = 0;
        for (vector<int> &f: flowers) {
            diff[f[0]]++;
            diff[f[1] + 1]--;
        }

        vector<int> pos;
        vector<int> prefix;
        int curr = 0;
        for (auto &[u, v]: diff) {
            pos.push_back(u);
            curr += v;
            prefix.push_back(curr);
        }
        vector<int> ans;
        for (int person: people) {
            int i = int(upper_bound(pos.begin(), pos.end(), person) - pos.begin() - 1);
            ans.push_back(prefix[i]);
        }
        return ans;
    }
};


// Initialize a sorted-map data structure difference with 0: 0.
// Iterate over each flower = [start, end] in flowers:
// Increment difference[start].
// Decrement difference[end + 1].
// Initialize two arrays, positions and prefix. Iterate over the keys of difference:
// positions contains all the keys in the order they are traversed.
// prefix contains the prefix sum of the corresponding values.
// Initialize the answer array ans. Iterate over each person in people:
// Perform a right-insertion index binary search on positions with person.
// Calculate i as the result of this binary search minus one.
// Add prefix[i] to ans.
// Return ans.

// I created an array diff and iterated over each flowers = [start, end] and performed diff[start]++ and diff[end + 1]-- for each flowers;
// Each index of diff represents the change of flowers people can see when cross this index.
// Thus, I could take a prefix sum of this diff array to find how many flowers can be seen at any given time with prefix[time]
// But the scale of time can be up to 10^9. So I used a map to store the diff array. diff[index] represents that the change at index is diff[index]
// Once I had this diff array. I created a prefix sum of diff and an array pos. prefix[i] is the number of flowers available at time pos[i]
// Finally, I iterated over people and find the ans for each person. I performed a binary search over pos to find the max index i that pos[i] is lower or equal to person. Then, prefix[i] is the ans for this person.