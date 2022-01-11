for q in range(int(input())):
    N, M, P = map(int,input().split())
    A = list(map(int,input().split()))
    B = list(map(int,input().split()))

    ans = 0
    for i in range(N):
        for j in range(M):
            if A[i]^B[j] < P and (A[i]*(A[i]^B[j])-1)%P==0:
                ans+=1;
    print(ans)