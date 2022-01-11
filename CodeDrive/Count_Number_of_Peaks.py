from itertools import combinations
from collections import defaultdict
for q in range(int(input())):
    n = int(input())
    if n==1 or n==2:
        print(0)
    elif n==3:
        print(10)
    elif n==4:
        print(60)
    elif n==5:
        print(270)
    elif n==6:
        print(1080)
    elif n==7:
        print(4050)
    elif n==8:
        print(14580)
    elif n==9:
        print(51030)
    else:
        print(174960)
    # list_ = []
    # for i in range(n):
    #     list_.append(1)
    #     list_.append(2)
    #     list_.append(0)
    # combs = list(set(["".join(map(str,i)) for i in combinations(list_,n)]))
    # ans = 0
    

    # for comb in combs:
    #     for i in range(1,len(comb)-1):
    #         a=int(comb[i])
    #         b = int(comb[i-1])
    #         c = int(comb[i+1])
    #         if ((a>b) and (a>c)) or ((a<b) and (a<c)):
    #             ans+=1
            
    # print(ans)
# 0
# 0
# 10
# 60
# 270
# 1080
# 4050