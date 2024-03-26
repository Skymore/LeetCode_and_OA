/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface ArrayReader {
 *   public:
 *     // Compares 4 different elements in the array
 *     // return 4 if the values of the 4 elements are the same (0 or 1).
 *     // return 2 if three elements have a value equal to 0 and one element has value equal to 1 or vice versa.
 *     // return 0 : if two element have a value equal to 0 and two elements have a value equal to 1.
 *     public int query(int a, int b, int c, int d);
 *
 *     // Returns the length of the array
 *     public int length();
 * };
 */

class Solution {
    public int guessMajority(ArrayReader reader) {
        int q0123 = reader.query(0, 1, 2, 3);
        int count0 = 1, count1 = 0, idx1 = -1;
        // calculate the number of elements that have the same value of a[0]
        for (int i = 4; i < reader.length(); i++) {
            if (reader.query(1, 2, 3, i) == q0123) {
                count0++;
            } else {
                count1++;
                idx1 = i;
            }
        }
        int q1234 = reader.query(1,2,3,4);

        // a[1] = a[0]?
        int q0234 = reader.query(0,2,3,4);
        if (q0234 == q1234) {
            count0++;
        } else {
            count1++;
            idx1 = 1;
        }
        // a[2] = a[0]?
        int q0134 = reader.query(0,1,3,4);
        if (q0134 == q1234) {
            count0++;
        } else {
            count1++;
            idx1 = 2;
        }
        //a[3] = a[0]?
        int q0124 = reader.query(0,1,2,4);
        if (q0124 == q1234) {
            count0++;
        } else {
            count1++;
            idx1 = 3;
        }

        if (count0 == count1) return -1;
        else if (count0 > count1) return 0;
        else return idx1;
    }
}