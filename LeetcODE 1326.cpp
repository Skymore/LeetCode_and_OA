class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> max_reach(n + 1);
        for (int i = 0; i <= n; i++) {
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);
            max_reach[start] = max(max_reach[start], end);
        }
        int taps = 0;
        int cur_end = 0;
        int next_end = 0;
        for (int i = 0; i <= n; i++) {
            if (i > cur_end)
                return -1;
            next_end = max(next_end, max_reach[i]);
            if (i == cur_end) {
                taps++;
                cur_end = next_end;
                if (cur_end >= n)
                    break;
            }
        }
        return taps;
    }
};

/*
1. For each tap, determine the leftmost position (start) and the rightmost
position (end) of its range.
2. Compute an auxiliary array named max_reach, similar to the problem 'Jump Game
II'. Let max_reach[i] represent the maximum end value among all taps with start
= i.
3. Initialize the variables: set taps = 0 and cur_end = 0. Here, taps represents
the number of taps used, and cur_end represents the rightmost position that can
be watered with the current number of taps.
4. At the beginning of each step, check if cur_end is smaller than i. If it is,
this means the segment [i-1, i] cannot be watered, and return -1.
5. During each step, select the tap that can water the furthest into the garden
as the next tap. Store this value in next_end, which represents the rightmost
position that can be watered with one more tap. If i is equal to cur_end, it
implies that the last tap selected can only water up to cur_end. In this case,
you will need an additional tap to water the positions from i to i+1. Add this
tap, and update next_end accordingly. After selected additional tap, check if
cur_end is greater than or equal to n. If it is, which means the whole garden is
watered, return taps.
*/