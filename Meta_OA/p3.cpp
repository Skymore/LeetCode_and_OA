/*
 * 题意：有一个n*m的网格，网格内有laser，laser所在的行和列不能进入。
 * 网格内有一个机器人，机器人沿直线行走，每次可以走到网格的边界，机器人不能走到laser所在的行和列。
 * 机器人的初始位置被保护不受laser影响，问机器人四个方向最多能走多少步。
 */
#include <iostream>
#include <vector>

using namespace std;

int solution(int n, int m, int x, int y, vector<vector<int>> laser) {
    vector<int> row(n + 1, 0);
    vector<int> column(m + 1, 0);
    for (const auto &l : laser) {
        row[l[0]] = 1;
        column[l[1]] = 1;
    }

    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int res = 0;
    for (const auto [dx, dy] : dir) {
        int step = 0;
        int nx = x + dx;
        int ny = y + dy;
        // 坐标从1开始
        while (nx > 0 && nx <= n && ny > 0 && ny <= m && !row[nx] && !column[ny]) {
            ++step;
            nx += dx;
            ny += dy;
        }
        res = max(res, step);
    }
    return res;
}


int main() {
    vector<vector<int>> laser = {{3, 3}, {2, 1}};
    cout << solution(3, 3, 1, 1, laser) << endl;
    /*
     * r 0 0
     * x 0 0
     * 0 0 x
     */
    cout << "reference answer: 1" << endl;
}
