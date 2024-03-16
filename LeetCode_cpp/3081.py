class Solution:
    def minimizeStringValue(self, s: str) -> str:
        count = collections.Counter(s)
        counts = [(count[char], char) for char in 'abcdefghijklmnopqrstuvwxyz']
        heapq.heapify(counts)
        
        ss = list(s)
        new_s = ''
        for i, char in enumerate(ss):
            if char == '?':
                min_count, min_char = heapq.heappop(counts)
                heapq.heappush(counts, (min_count+1, min_char))
                new_s += min_char
                
        sorted_s = ''.join(sorted(new_s))
        
        sorted_index = 0

        for i, char in enumerate(ss):
            if char == '?':
                ss[i] = sorted_s[sorted_index]
                sorted_index += 1

        ret = ''.join(ss)

        return ret