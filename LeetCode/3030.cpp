class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int th) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> num(m, vector<int>(n, 0));
        vector<vector<int>> tot(m, vector<int>(n, 0));
        vector<vector<int>> ans(m, vector<int>(n, 0));
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        for (int row = 0; row < m - 2; row++) {
            for (int col = 0; col < n - 2; col++) {
                //cout << row << col << endl;
                bool is_region = true;
                for (int i = row; i < row + 3; i++) {
                    for (int j = col; j < col + 3; j++) {
                        for (auto [dx, dy] : dirs) {
                            int newX = i + dx;
                            int newY = j + dy;
                            // 确保newX和newY在数组的边界内
                            if (newX >= row && newX < row + 3 && newY >= col && newY < col + 3) {
                                // 在这里执行您的逻辑，例如累加到tot或num数组
                                if (abs(image[i][j] - image[newX][newY]) > th) {
                                    is_region = false;
                                    //cout << image[i][j] << " " << image[newX][newY] << "false" << endl;
                                }
                            }
                        }
                    }
                }
                if (is_region) {
                    //cout << "haha" << endl;
                    int sum = 0;
                    for (int i = row; i < row + 3; i++) {
                        for (int j = col; j < col + 3; j++) {
                            sum += image[i][j];
                        }
                    }
                    sum /= 9;
                    for (int i = row; i < row + 3; i++) {
                        for (int j = col; j < col + 3; j++) {
                            tot[i][j] += sum;
                            num[i][j] += 1;
                        }
                    }
                    
                }
            }
        }
        
        
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (num[row][col] > 0) ans[row][col] = tot[row][col] / num[row][col];
                else ans[row][col] = image[row][col];
            }
        }
        return ans;
    }
};