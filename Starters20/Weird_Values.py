from collections import defaultdict

for q in range(int(input())):
    n = int(input())
    arr = list(map(int,input().split()))

    dp = {}
    freq = defaultdict(lambda :0)
    sum_weird = 0
    for i in range(len(arr)):
        for j in range(i, min(i+2, len(arr))):
            subarr = arr[i:j+1]
            weird = 0
            for a in subarr:
                freq[(i, j, a)] = subarr.count(a)
                if a==subarr.count(a):
                    weird+=1
            dp[(i,j)] = weird
            sum_weird+=weird
    for i in range(3,len(arr)+1):
        for j in range(len(arr)):
            weird=0
            if j+i > len(arr):
                break
            subarr = arr[j:j+i]
            
            if subarr[0] not in subarr[1:-1] and subarr[-1] not in subarr[1:-1]:
                weird+=dp[(j+1, j+i-2)]
                if subarr[0]==1:
                    weird+=1
                if subarr[-1]==1:
                    weird+=1
                if subarr[0]==subarr[-1]:
                    if subarr[0]==2:
                        weird+=2
                    freq[(j, j+i-1, subarr[-1])] = 2
                    freq[(j, j+i-1, subarr[0])] = 2
                else:
                    freq[(j, j+i-1, subarr[-1])] = 1
                    freq[(j, j+i-1, subarr[0])] = 1

            else:
                if subarr[0] != subarr[-1]:
                    weird+=dp[(j+1, j+i-2)]
                    if freq[(j+1, j+i-2, subarr[0])] == subarr[0]:
                        weird-=subarr[0]
                    else:
                        if freq[(j+1, j+i-2, subarr[0])]+1 == subarr[0]:
                            weird+=subarr[0]
                    freq[(j, j+i-1, subarr[0])] = max(0,freq[(j+1, j+i-2, subarr[0])]+1)
                    if freq[(j+1, j+i-2, subarr[-1])] == subarr[-1]:
                        weird-=subarr[-1]
                    else:

                        if freq[(j+1, j+i-2, subarr[-1])]+1 == subarr[-1]:
                            weird += subarr[-1]
                    freq[(j, j+i-1, subarr[-1])] = max(0,freq[(j+1, j+i-2, subarr[-1])]+1)

                else:
                    weird+=dp[(j+1, j+i-2)]
                    if freq[(j+1, j+i-2, subarr[0])] == subarr[0]:
                        weird -= subarr[0]
                    else:
                        if freq[(j+1, j+i-2, subarr[0])]+2 == subarr[0]:
                            weird+=subarr[0] 
                    freq[(j, j+i-1, subarr[0])] = max(freq[(j+1, j+i-2, subarr[0])]+2,0)
                    freq[(j, j+i-1, subarr[-1])] = max(0,freq[(j+1, j+i-2, subarr[-1])]+2)

            print(subarr, weird)
            dp[(j,j+i-1)] = max(weird,0)
            sum_weird+=max(weird, 0)
    print(sum_weird)

            
'''
1
4
1 2 1 2
'''
