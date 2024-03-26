# Type: KMP algorithm
# Description: KMP algorithm implementation

def prefix_function(s: str) -> list[int]:
    # Calculate the prefix function of the string.
    # The prefix function is an array pi of length n, where pi[i] is the length of the longest proper prefix of the
    # substring s[0…i] which is also a suffix of this substring.
    # The proper prefix is a prefix that is not equal to the string itself.

    # explanation:
    # https://www.youtube.com/watch?v=GTJr8OvyEVQ
    n = len(s)
    pi = [0] * n
    for i in range(1, n):
        j = pi[i - 1]
        while j > 0 and s[i] != s[j]:
            j = pi[j - 1]
        if s[i] == s[j]:
            j += 1
        pi[i] = j
    return pi


def find_pattern(s: str, pattern: str) -> list[int]:
    n = len(s)
    m = len(pattern)
    pi = prefix_function(pattern + '#' + s)
    result = []
    for i in range(m + 1, n + 1):
        if pi[i] == m:
            result.append(i - 2 * m)
    return result


# KMP (Knuth-Morris-Pratt) 算法是一种高效的字符串匹配算法，它解决了朴素字符串匹配算法中存在的一个主要问题：当匹配失败时，不需要将文本字符串的指针i
# 回退到之前的位置。这是通过预处理模式字符串来实现的，预处理结果存储在一个称为"部分匹配表"（也称为"失败函数"或"前缀函数"）的数组中。这个表允许算法在匹配失败时跳过一些不必要的比较。
#
# 为什么i不需要回退？
# 在KMP算法中，i代表当前正在考察的文本字符串中的位置，而j代表模式字符串中的位置。当在j位置发生匹配失败时，KMP算法利用已经计算好的部分匹配表来决定j的下一个位置，而文本字符串的指针i不需要回退，因为部分匹配表已经告诉我们在模式字符串中有多长的相同前缀和后缀。这样，我们可以保持文本字符串的指针i前进，避免重新检查已经匹配过的字符。
#
# 部分匹配表的作用
# 部分匹配表（也称为next数组）为每个位置j记录了在模式字符串的j位置发生不匹配时，j应该跳转到哪个位置。这个跳转基于模式字符串前j个字符中，最长的相同的前缀和后缀的长度。因此，当发生不匹配时：


def kmp(s: str, pattern: str) -> list[int]:

    def compute_pi(s: str) -> list[int]:
        n = len(s)
        pi = [0] * n
        for i in range(1, n):
            j = pi[i - 1]
            while j > 0 and s[i] != s[j]:
                j = pi[j - 1]
            if s[i] == s[j]:
                j += 1
            pi[i] = j
        return pi

    n = len(s)
    m = len(pattern)
    pi = compute_pi(s)
    result = []
    j = 0
    for i in range(n):
        while j > 0 and s[i] != s[j]:
            j = pi[j - 1]
        if s[i] == s[j]:
            j += 1
        if j == m:
            result.append(i - m + 1)
            j = pi[j - 1]
    return result





def occurrences(s: str, pattern: str) -> int:
    return len(find_pattern(s, pattern))


def occurences_of_prefixes(s: str) -> list[int]:
    pi = prefix_function(s)
    n = len(s)
    result = [0] * (n + 1)
    for i in range(n):
        result[pi[i]] += 1
    for i in range(n - 1, 0, -1):
        result[pi[i - 1]] += result[i]
    for i in range(n + 1):
        result[i] += 1
    return result


print(prefix_function('abacaba'))  # [0, 0, 1, 0, 1, 2, 3]
print(occurences_of_prefixes('abacaba'))  # [8, 4, 2, 2, 1, 1, 1, 1]
