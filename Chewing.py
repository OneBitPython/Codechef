N, K = map(int, input().split())
arr = list(map(int,input().split()))

arr.sort()

l = 0
r = N-1
ans = 0
while l!=r:
    if arr[l] + arr[r] < K:
        ans+=r-l
        l+=1
    else:
        r-=1
print(ans)