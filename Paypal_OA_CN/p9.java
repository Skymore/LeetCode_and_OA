
class p9 {
    public static String rollTheString(String s, int[] a) {
        char[] arr = s.toCharArray();
        // 差分数组
        int [] d = new int[s.length() + 2];
        System.out.println(d.length);
        for (int ai: a) {
            d[0]++;
            d[ai]--;
        }
        for (int i = 1; i < s.length(); i++) {
            d[i] += d[i - 1];
        }
        for (int i = 0; i < s.length(); i++) {
            arr[i] = (char)('a' + (arr[i] - 'a' + d[i]) % 26);
        }

        return new String(arr);
    }
    public static void main(String[] args) {
        System.out.println(rollTheString("abz", new int[]{3, 2, 1}));
    }
}

// Time complexity: O(n)