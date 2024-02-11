class Solution:
    def maxPalindromesAfterOperations(self, words: List[str]) -> int:
        sorted_words = sorted(words, key = len)
        combined_string = ''.join(words)
        char_count = Counter(combined_string)
        odd = sum(1 for count in char_count.values() if count % 2 != 0)
        paired = len(combined_string) - odd
        ans = 0
        for i in range(len(sorted_words)):
            length = len(sorted_words[i])
            if length % 2 != 0 and odd > 0:
                odd -= 1
                length -= 1
            if paired >= length:
                paired -= length
                ans += 1
        return ans