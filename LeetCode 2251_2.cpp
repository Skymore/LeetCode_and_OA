//
// Created by 陶睿 on 10/25/23.
//
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Solution2 {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> starts;
        vector<int> ends;
        for (auto& f: flowers) {
            starts.emplace_back(f[0]);
            ends.emplace_back(f[1]);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        vector<int> ans;
        for (int person: people) {
            int i = upper_bound(starts.begin(), starts.end(), person) - starts.begin();
            int j = lower_bound(ends.begin(), ends.end(), person) - ends.begin();
            ans.emplace_back(i - j);
        }
        return ans;
    }
};

// the number of flowers we see is the number of flowers that have already started blooming minus the amount of flowers have finished blooming.

//Create two arrays starts and ends.
//Iterate over each flower = [start, end] in flowers:
//Add start to starts.
//Add end to ends.
//Sort both starts and ends.
//Initialize the answer array ans and iterate over each person in people:
//Perform a binary search on starts for the rightmost insertion index of person to find i.
//Perform a binary search on ends for the left insertion index of person to find j.
//Add i - j to ans.
//Return ans.