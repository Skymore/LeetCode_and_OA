class Solution {
        // Define getHash as a private method
    private long getHash(long[] h, long[] p, int l, int r) {
        return h[r] - h[l - 1] * p[r - l + 1];
    }

    public int minimumTimeToInitialState(String word, int k) {
        int n = word.length(); // Length of the string

        long P = 131; // A large prime number for hashing
        long[] p = new long[n + 1]; // Array to store powers of P for hash calculation
        long[] h = new long[n + 1]; // Array to store prefix hash values of the string
        p[0] = 1;

        // Initialize p and h arrays
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] * P;
            h[i] = h[i - 1] * P + word.charAt(i - 1);
        }

        for (int i = k; i <= n; i += k) {
            // Compare the hash value of the substring starting from the i-th character
            // with the beginning substring's hash value using the getHash method
            if (getHash(h, p, i + 1, n) == getHash(h, p, 1, n - i)) {
                return i / k; // If matched, return the number of moves required
            }
        }

        // If no match is found
        return (n + k - 1) / k;
    }
}