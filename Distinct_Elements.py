def distinctSubseqII(S):
    new_s = ""
    for i in S:
        new_s+=(str(i))
    dp = [1]
    last = {}
    for i, x in enumerate(new_s):
        freq = {}
        for j in new_s[:i]:
            if j not in freq:
                freq[j]=0
            freq[j]+=1
        freq = sorted(freq.values(),reverse=True)
        if not freq:
            freq = [1]
        dp.append(dp[-1] * 2)
        if x in last:
            dp[-1] -= dp[last[x]]
        last[x] = i

    return (dp[-1] - 1) % (10**9 + 7)
for q in range(int(input())):
    N = int(input())
    arr = map(int,input().split())
    print(distinctSubseqII(arr))
