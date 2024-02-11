def prefix_function(s: str) -> list[int]:
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


def kmp(s: str, pattern: str) -> list[int]:
    n = len(s)
    m = len(pattern)
    pi = prefix_function(pattern)
    result = []
    j = 0
    for i in range(n):
        while j > 0 and s[i] != pattern[j]:
            j = pi[j - 1]
        if s[i] == pattern[j]:
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
