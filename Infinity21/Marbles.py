from collections import Counter
for q in range(int(input())):
    n = int(input())
    p = input()
    s = input()
    vowels = "aeiou"
    final = float('inf')
    for change_to in "abcdefghijklmnopqrstuvwxyz":
        ans = 0
        idx = 0

        for i, j in zip(p,s):
            if i=="?": 
                i = change_to
            if j == "?": 
                j = change_to
            
            if i!=j:
                if j in vowels and i not in vowels:
                    ans+=1
                elif i in vowels and j not in vowels:
                    ans+=1
                else:
                    ans+=2
            idx+=1
        final = min(final, ans)
    print(final)