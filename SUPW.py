n = int(input())
arr = list(map(int,input().split()))

ans = 0

if len(arr)<=3:
    print(min(arr))
else:
    dp = [arr[0],arr[1],arr[2]]
    for i in range(3, len(arr)):
        dp.append(min(dp[-3::1])+arr[i])
    print(min(dp[-3::1]))
