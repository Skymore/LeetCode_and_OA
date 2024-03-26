class Solution:
    def minimumDeletions(self, word: str, k: int) -> int:
        freq = Counter(word)
        sorted_f = sorted(freq.values())
        ans = float('inf')

        for low_freq in range(sorted_f[0], sorted_f[-1] + 1):
            high_freq = low_freq + k
            total_to_delete = 0

            for f in sorted_f:
                if f < low_freq:
                    total_to_delete += f
                elif f > high_freq:
                    total_to_delete += f - high_freq

            ans = min(ans, total_to_delete)

        return ans
