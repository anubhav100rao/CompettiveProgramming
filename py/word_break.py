def wordBreakDp(word, wordList):
    dp = [False] * (len(word) + 1)
    dp[0] = True
    for i in range(1, len(word) + 1):
        for j in range(i):
            if dp[j] and word[j:i] in wordList:
                dp[i] = True
                break
    return dp[-1]

def wordBreak(word, wordList):
    if word == "":
        return True
    return any([(word[:i] in wordList and wordBreak(word[i:], wordList)) for i in range(len(word) + 1)])