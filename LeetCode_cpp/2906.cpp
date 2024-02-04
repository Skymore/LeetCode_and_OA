#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<long long> rows, prefix_r{1}, suffix_r{1};
        for (const auto &r : grid) {
            rows.push_back(accumulate(r.begin(), r.end(), 1LL, [](long long res, int v){
                return (res * v) % 12345;
            }));
        }

        for (int i = 0; i < n; i++) {
            prefix_r.push_back(prefix_r.back() * rows[i] % 12345);
            suffix_r.push_back(suffix_r.back() * rows[n - 1 - i] % 12345);
        }
        reverse(suffix_r.begin(), suffix_r.end());

        vector<vector<int>> res(n, vector<int> (m, 1));
        for (int i = 0; i < n; i++) {
            vector<long long> prefix{1}, suffix{1};
            for (int j = 0; j < m; j++) {
                prefix.push_back(prefix.back() * grid[i][j] % 12345);
                suffix.push_back(suffix.back() * grid[i][m - 1 - j] % 12345);
            }
            reverse(suffix.begin(), suffix.end());
            for (int j = 0; j < n; j++) {
                res[i][j] = prefix_r[i] * suffix_r[i] * prefix[j] * suffix[j] % 12345;
            }
        }
        return res;

    }
};

/*
If our modulo is a price, I could get the product of all cells, and then use inverse modulo
to do a modular division.
Unfortunately, '12345' is not a prime, so I cannot do that...
Instead, for every cell, I calculated for prefix/suffix products:
  'prefix_r[i]' is the product of all rows above i.
  'suffix_r[i]' is the product of all row below i
  'prefix[j]' is the product of all cells in the current row before j
  'suffix[j]' is the product of all cells in the current row after j
First I calculated the product of all cells in each row as row.
*/