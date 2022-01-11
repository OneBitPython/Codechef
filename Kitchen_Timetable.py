for q in range(int(input())):
    N = int(input())
    arr = [0] 
    arr.extend(list(map(int,input().split())))
    b = list(map(int,input().split()))

    ans = 0
    for i in range(N):
        time_r = arr[i+1]-arr[i]
        if time_r >= b[i]:
            ans+=1
    print(ans)